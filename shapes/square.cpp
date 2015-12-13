#include "square.h"

CSquare::CSquare(double x, double y, double width)
        : CShape_Base(x, y),
          m_dWidth(width)
{
}


CSquare::~CSquare()
{
}


CShape_Base::EShapeType CSquare::type() const
{
    return  CShape_Base::eSquare;
}


double CSquare::get_Width() const
{
    return m_dWidth;
}
