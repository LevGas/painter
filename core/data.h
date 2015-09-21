#ifndef CDATA_H
#define CDATA_H

#include "subject.h"
#include "cord_convertor.h"

#include <list>

class CShape_Base;

class CData : public CSubject
{
public:
    CData();
    ~CData();

    void setPageSize(int w, int h);
    void notify_remove(int indx);
    void add(CShape_Base* pShape);
    void remove(int indx);
    void clear();

    CShape_Base* lastShape() const;
    int count() const;
    int getWidth() const;
    int getHeight() const;

private:
    std::list<CShape_Base*> m_lstSahpes;
    int m_nPageWidth;
    int m_nPageHeight;
    CCordConvertor *m_pCordConvertor;

};

#endif // CDATA_H
