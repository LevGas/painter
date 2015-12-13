#ifndef CCORDCONVERTOR_H
#define CCORDCONVERTOR_H

class CCordConvertor
{
public:
    CCordConvertor(int origin_x = 0, int origin_y = 0, int pageWidth = 0, int pageHeight = 0);
    ~CCordConvertor();

    void setOrigin(int x, int y);
    void setSize(int w, int h);

    int convert_X(int x) const;
    int convert_Y(int y) const;

    double convert_X(double x) const;
    double convert_Y(double y) const;

private:
    int m_nOrigin_x;
    int m_nOrigin_y;
    int m_nPageWidth;
    int m_nPageHeight;
};

#endif // CCORDCONVERTOR_H
