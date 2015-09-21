#ifndef CPAGE_H
#define CPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "data.h"
#include "observer.h"
#include "subject.h"
#include "cord_convertor.h"

typedef class CPage : public QWidget, public CObserver
{
public:
    CPage(CSubject *pSubject, QWidget *parent = 0);
    ~CPage();

    void setPageSize(int w, int h);

    void update();
    void remove_Shape(int indx);

private:
    void drow_cord_system();

private:
    QGraphicsScene* m_pScene;
    QGraphicsView* m_pView;
    int m_nWidth;
    int m_nHeight;
    int m_nItemCount;

} page;

#endif // CPAGE_H
