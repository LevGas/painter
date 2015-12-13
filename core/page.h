#ifndef CPAGE_H
#define CPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "data.h"
#include "observer.h"
#include "subject.h"
#include "cord_convertor.h"

#include "shapes/rectangle.h"
#include "shapes/circle.h"
#include "shapes/square.h"
#include "shapes/line.h"

typedef class CPage : public QWidget, public CObserver
{
public:
    CPage(CData *pData, QWidget *parent = 0);
    ~CPage();

    void setPageSize(int w, int h);

    void update();
    void remove_Shape(int indx);

private:
    void draw_cord_system();

public:
    void draw_rect(CRectangle *pRect);
    void draw_circle(CCircle *pCircle);
    void draw_square(CSquare *pSquare);
    void draw_line(CLine *pLine);


private:
    CData* m_pData;
    QGraphicsScene* m_pScene;
    QGraphicsView* m_pView;
    CCordConvertor* m_pCoordConvertor;
    int m_nWidth;
    int m_nHeight;
    int m_nItemCount;

} page;

#endif // CPAGE_H
