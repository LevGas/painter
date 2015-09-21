#ifndef CCIRCLE_H
#define CCIRCLE_H

#include <shape_base.h>

class CCircle : public CShape_Base
{
public:
    CCircle(double x, double y, double r);
    ~CCircle();

    CShape_Base::EShapeType type() const;

    void setRadius(double r);
    double getRadius() const;

private:
    double m_dRadius;

};

#endif // CCIRCLE_H
