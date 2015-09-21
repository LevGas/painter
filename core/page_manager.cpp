#include "page_manager.h"

CPageManager::CPageManager()
               : m_lstPages(QList<CPage*>()),
                 m_nActivePage(-1)
{
}

CPageManager::~CPageManager()
{
}

CPageManager* CPageManager::m_pInstace = 0;

CPageManager* CPageManager::getInstance()
{
    if (m_pInstace == 0)
    {
        m_pInstace = new CPageManager;
    }
    return m_pInstace;
}

void CPageManager::deleteInstance()
{
    if (m_pInstace != 0)
    {
        delete m_pInstace;
        m_pInstace = 0;
    }
}

void CPageManager::setActivePage(int indx)
{
    if (indx >= 0 && indx < m_lstPages.size())
    {
        m_nActivePage = indx;
    }
    else
    {
        m_nActivePage = -1;
    }
}

CPage* CPageManager::getActivePage() const
{
    CPage *pRet = 0;
    if (m_nActivePage != -1)
    {
        pRet = m_lstPages[m_nActivePage];
    }
    return pRet;
}

void CPageManager::appendPage(CPage *pPage)
{
    if (pPage != 0)
    {
        m_lstPages.append(pPage);
    }
}

int CPageManager::getActivePageIndex() const
{
    return m_nActivePage;
}

void CPageManager::removePage(int indx)
{
    if (indx >= 0 && indx < m_lstPages.size())
    {
        delete m_lstPages[indx];
        m_lstPages.removeAt(indx);
    }
}

int CPageManager::count() const
{
    return m_lstPages.count();
}
