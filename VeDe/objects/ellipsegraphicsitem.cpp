#include "ellipsegraphicsitem.h"
#include "converters.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>

EllipseGraphicsItem::EllipseGraphicsItem(std::shared_ptr<gx::Ellipse> ellipse)
    :BaseShapeItem(ellipse), m_ellipse(ellipse)
{
}

void EllipseGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    BaseShapeItem::paint(painter,option,widget);
    painter->drawEllipse(gx::Converters::toPoint(m_ellipse->center()), m_ellipse->radius().x(), m_ellipse->radius().y());
//    painter->setBrush(QBrush(QColor(255,255,255,0)));
//    painter->drawRect(boundingRect());
}
