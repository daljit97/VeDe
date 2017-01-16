#include "workspace.h"
#include <QBrush>
#include <QPalette>
#include <QPixmap>
#include <QWheelEvent>
#include <QTimeLine>
#include <QApplication>

Workspace::Workspace(CanvasImpl *canvas, QWidget *parent)
    :QGraphicsView(parent), m_canvas(canvas)
{
    QGraphicsScene* scene = new WorkspaceScene(canvas, this);
    scene->installEventFilter(scene);
    scene->setBackgroundBrush(QBrush(QPixmap(":/images/grid.png")));
    scene->addItem(canvas);
    canvas->setFlag(QGraphicsItem::ItemIsFocusable);
    canvas->setFlag(QGraphicsItem::ItemIsSelectable);
//    scene->setFocusItem(canvas);
    setFocusPolicy(Qt::WheelFocus);
    setFocus();
    setScene(scene);
    setMouseTracking(true);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    qApp->installEventFilter(this);
}

Workspace::~Workspace()
{
}

bool Workspace::eventFilter(QObject* o,QEvent* e)
{
    if(e->type()==QEvent::KeyPress)
    {
//        qWarning()<<"The bad guy which steals the keyevent is"<<o;
    }

    return false;
}

void Workspace::wheelEvent(QWheelEvent *event)
{
//    m_canvas->wheelEvent(event);

    if((event->modifiers() & Qt::ControlModifier) == Qt::ControlModifier)
    {
        handleZooming(event);
        event->accept();
    }
}

void Workspace::handleZooming(QWheelEvent *event)
{
    QPoint  pos  = event->pos();
    QPointF posf = this->mapToScene(pos);

    double by;
    double angle = event->angleDelta().y();

    if      (angle > 0) { by = 1 + ( angle / 180 * 0.1); }
    else if (angle < 0) { by = 1 - (-angle / 180 * 0.1); }
    else                { by = 1; }

    this->scale(by, by);

    double w = this->viewport()->width();
    double h = this->viewport()->height();

    double wf = this->mapToScene(QPoint(w-1, 0)).x()
                    - this->mapToScene(QPoint(0,0)).x();
    double hf = this->mapToScene(QPoint(0, h-1)).y()
                    - this->mapToScene(QPoint(0,0)).y();

    double lf = posf.x() - pos.x() * wf / w;
    double tf = posf.y() - pos.y() * hf / h;

    /* try to set viewport properly */
    this->ensureVisible(lf, tf, wf, hf, 0, 0);

    QPointF newPos = this->mapToScene(pos);

    /* readjust according to the still remaining offset/drift
     * I don't know how to do this any other way */
    this->ensureVisible(QRectF(QPointF(lf, tf) - newPos + posf,
                    QSizeF(wf, hf)), 0, 0);
}
