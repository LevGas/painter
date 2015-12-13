#ifndef CSQUARE_H
#define CSQUARE_H

#include "shape_base.h"


class CSquare : public CShape_Base
{
public:
    CSquare(double x, double y, double width);
    ~CSquare();

    CShape_Base::EShapeType type() const;


    double get_Width() const;

private:
    double m_dWidth;

};

#endif // CSQUARE_H
