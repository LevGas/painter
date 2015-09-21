#include "circle.h"

CCircle::CCircle(double x, double y, double r)
        : CShape_Base(x, y),
          m_dRadius(r)
{
}

CCircle::~CCircle()
{
}

void CCircle::setRadius(double r)
{
    m_dRadius = r;
}

double CCircle::getRadius() const
{
    return m_dRadius;
}

CShape_Base::EShapeType CCircle::type() const
{
    return CShape_Base::eCircle;
}
