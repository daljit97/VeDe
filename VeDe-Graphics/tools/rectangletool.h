#ifndef RECTANGLETOOL_H
#define RECTANGLETOOL_H

#include "shapetool.h"
#include "objects/rectangle.h"

namespace gx
{
class RectangleTool : public ShapeTool
{
public:
    RectangleTool(Canvas* canvas);

private:
    std::shared_ptr<Rectangle> m_rect;
    Vertex m_anchorPoint;

    void restrictPoints(const Vertex &cursor, Vertex& upLeft, Vertex& downRight);
    void moveEndPoint();
};
}

#endif // RECTANGLETOOL_H
