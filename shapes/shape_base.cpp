#include "shape_base.h"

CShape_Base::CShape_Base(double x, double y)
            : m_dCord_x(x),
              m_dCord_y(y)
{
}

CShape_Base::CShape_Base(const CShape_Base & other)
            : m_dCord_x(other.m_dCord_x),
              m_dCord_y(other.m_dCord_y)
{
}

CShape_Base::EShapeType CShape_Base::type() const
{
    return eBase;
}
