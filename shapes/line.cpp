#include "line.h"

CLine::CLine(double x1, double y1, double x2, double y2)
       : CShape_Base(x1, y1),
         m_dDest_X(x2),
         m_dDest_Y(y2)
{
}


CShape_Base::EShapeType CLine::type() const
{
    return CShape_Base::eLine;
}


double CLine::get_Dest_X() const
{
    return m_dDest_X;
}

double CLine::get_Dest_Y() const
{
    return m_dDest_Y;
}

void CLine::set_Dest_X(double x)
{
    m_dDest_X = x;
}

void CLine::set_Dest_Y(double y)
{
    m_dDest_Y = y;
}
