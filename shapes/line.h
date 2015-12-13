#ifndef CLINE_H
#define CLINE_H

#include "shape_base.h"


class CLine : public CShape_Base
{
public:
    CLine(double x1, double y1, double x2, double y2);

    EShapeType type() const;

    void set_Dest_X(double);
    void set_Dest_Y(double);

    double get_Dest_X() const;
    double get_Dest_Y() const;

private:
    double m_dDest_X;
    double m_dDest_Y;

};

#endif // CLINE_H
