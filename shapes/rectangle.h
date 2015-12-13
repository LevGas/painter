#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "shape_base.h"

class CRectangle : public CShape_Base
{
public:
    CRectangle(double x, double y, double w, double h);
    CRectangle(const CRectangle & other);
    virtual ~CRectangle();

    CShape_Base::EShapeType type() const;


    double get_Height() const;
    double get_Width() const;

private:
    double m_dWidth;
    double m_dHeight;

};

#endif // CRECTANGLE_H
