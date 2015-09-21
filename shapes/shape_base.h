#ifndef CSHAPE_BASE_H
#define CSHAPE_BASE_H

class CData;

class CShape_Base
{
public:
    enum EShapeType
    {
        eBase = 0,
        eRect = 1,
        eCircle = 2,
        eSquaer = 3,
        eLine = 4
    };

public:
    CShape_Base(double x, double y);
    CShape_Base(const CShape_Base & other);

    virtual ~CShape_Base()
    {}

    virtual EShapeType type() const;

    double get_X() const
    {
        return m_dCord_x;
    }
    double get_Y() const
    {
        return m_dCord_y;
    }

    void set_X(double x)
    {
        m_dCord_x = x;
    }

    void set_Y(double y)
    {
        m_dCord_y = y;
    }

private:
    double m_dCord_x;
    double m_dCord_y;


};

#endif // CSHAPE_BASE_H
