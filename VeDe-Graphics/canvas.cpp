#include "canvas.h"
#include "tools/tool.h"

gx::Canvas::Canvas(QObject *parent)
    :PropertyHolder(parent), m_root(new Layer), m_currLayer(new Layer)
{
    initCommon();
    m_root->addChild(m_currLayer, m_root);
    m_root->setId(m_idCount++);
    m_currLayer->setId(m_idCount++);
}

gx::Canvas::Canvas(std::shared_ptr<GObject> *root, QObject *parent)
    :PropertyHolder(parent)
{
    initCommon();
    m_root = std::move(*root);
}

void gx::Canvas::initCommon()
{
    m_currCommand = 0;
    m_currTool = nullptr;
    m_idCount = 0;
}

gx::Canvas::~Canvas()
{
    foreach(auto command, m_commandHistory)
    {
        delete command;
    }

    m_root->removeAllChildren();
}

std::shared_ptr<gx::GObject> gx::Canvas::root()
{
    return m_root;
}

int gx::Canvas::executeCommand(gx::Command* command)
{
    int result = command->execute();

    if(result == 0)
    {
        if(m_currCommand != m_commandHistory.size())
        {
            for(auto it = m_commandHistory.begin() + m_currCommand; it != m_commandHistory.end(); ++it)
            {
                delete (*it);
            }

            m_commandHistory.erase(m_commandHistory.begin() + m_currCommand, m_commandHistory.end());
        }

        m_commandHistory.append(command);
        m_currCommand++;
    }

    redraw();
    return result;
}

int gx::Canvas::undoCommand()
{
    int result = -1;
    if(m_currCommand > 0)
    {
        result = m_commandHistory.at(m_currCommand - 1)->undo();

        if(result == 0)
        {
            m_currCommand--;
        }
    }

    redraw();
    return result;
}

int gx::Canvas::redoCommand()
{
    int result = -1;
    if(m_currCommand < m_commandHistory.size())
    {
        result = m_commandHistory.at(m_currCommand)->execute();

        if(result == 0)
        {
            m_currCommand++;
        }
    }

    redraw();
    return result;
}

void gx::Canvas::handleTransition(const Transition &transition)
{
    if(m_currTool != nullptr)
    {
        m_currTool->handleEvent(transition);
    }
}

void gx::Canvas::addToCurrLayer(std::shared_ptr<gx::GObject> object)
{
    object->setId(m_idCount++);
    m_currLayer->addChild(object, m_currLayer);
}

void gx::Canvas::changeCurrTool(gx::Tool *newTool)
{
    if(m_currTool != nullptr)
    {
        m_currTool->setActive(false);
    }

    m_currTool = newTool;
    m_currTool->setActive(true);
    emit activeToolChanged(m_currTool);
}
