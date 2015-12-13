#include "cord_convertor.h"

CCordConvertor::CCordConvertor(int origin_x, int origin_y, int pageWidth, int pageHeight)
                : m_nOrigin_x(origin_x),
                  m_nOrigin_y(origin_y),
                  m_nPageWidth(pageWidth),
                  m_nPageHeight(pageHeight)
{
}

CCordConvertor::~CCordConvertor()
{
}

int CCordConvertor::convert_X(int x) const
{
    int new_x = x + m_nOrigin_x;
    return new_x;
}

int CCordConvertor::convert_Y(int y) const
{
    int new_y = m_nOrigin_y - y;
    return new_y;
}


double CCordConvertor::convert_X(double x) const
{
    double new_x = x + m_nOrigin_x;
    return new_x;
}


double CCordConvertor::convert_Y(double y) const
{
    double new_y = m_nOrigin_y - y;
    return new_y;
}


void CCordConvertor::setOrigin(int x, int y)
{
    m_nOrigin_x = x;
    m_nOrigin_y = y;
}

void CCordConvertor::setSize(int w, int h)
{
    m_nPageWidth = w;
    m_nPageHeight = h;
}

