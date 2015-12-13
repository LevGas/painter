#include "data.h"
#include "shapes/shape_base.h"
#include "page.h"
#include <list>


CData::CData()
       : CSubject()
{
}

CData::~CData()
{
    std::list<CShape_Base*>::iterator it = m_lstSahpes.begin();
    while (it != m_lstSahpes.end())
    {
        delete (*it);
        m_lstSahpes.erase(it);
    }
    notify();
}

void CData::add(CShape_Base* pShape)
{
    std::list<CShape_Base*>::iterator it = m_lstSahpes.begin();
    while (it != m_lstSahpes.end())
    {
        if ((*it) == pShape)
            break;

        ++it;
    }

    if (it == m_lstSahpes.end())
    {
 //       pShape->set_X(m_pCordConvertor->convert_X(pShape->get_X()));
 //       pShape->set_Y(m_pCordConvertor->convert_y(pShape->get_Y()));

//        if (pShape->type() == CShape_Base::eLine)
  //      {
   //         CLine *pLine = static_cast<CLine*>(pShape);
    //        pLine->set_Dest_X(m_pCordConvertor->convert_X(pLine->get_Dest_X()));
     //       pLine->set_Dest_Y(m_pCordConvertor->convert_y(pLine->get_Dest_Y()));

        //    pShape = pLine;
        //}

        m_lstSahpes.push_back(pShape);
        notify();
    }
}

void CData::remove(int indx)
{
    if (indx >= 0 && indx < (int)m_lstSahpes.size())
    {
        std::list<CShape_Base*>::iterator it = m_lstSahpes.begin();
        for (int i = 0; i <= indx; ++i)
        {
            ++it;
        }
        m_lstSahpes.erase(it);
        notify_remove(indx);
    }
}


void CData::clear()
{
    m_lstSahpes.clear();
    notify();
}


CShape_Base* CData::lastShape() const
{
    if (!m_lstSahpes.empty())
    {
        return m_lstSahpes.back();
    }
    return 0;
}

int CData::count() const
{
    return m_lstSahpes.size();
}

void CData::notify_remove(int indx)
{
    std::list<CObserver*>::iterator it = m_lstObservers.begin();
    while (it != m_lstObservers.end())
    {
        CPage *pPage = dynamic_cast<CPage*>(*it);
        pPage->remove_Shape(indx);
        ++it;
    }
}

void CData::setPageSize(int w, int h)
{
    m_nPageHeight = h;
    m_nPageWidth = w;
}

int CData::getHeight() const
{
    return m_nPageHeight;
}

int CData::getWidth() const
{
    return m_nPageWidth;
}
