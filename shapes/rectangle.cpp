#include "rectangle.h"

CRectangle::CRectangle(double x, double y, double w, double h)
            : CShape_Base(x, y),
              m_dWidth(w),
              m_dHeight(h)

{
}

CRectangle::CRectangle(const CRectangle & other)
            : CShape_Base(other),
              m_dWidth(other.m_dWidth),
              m_dHeight(other.m_dHeight)

{
}

CRectangle::~CRectangle()
{
}

CShape_Base::EShapeType CRectangle::type() const
{
    return CShape_Base::eRect;
}

double CRectangle::get_Height() const
{
    return m_dHeight;
}

double CRectangle::get_Width() const
{
    return m_dWidth;
}
