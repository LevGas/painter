#include "data_manager.h"

CDataManager::CDataManager()
              : m_lstData(QList<CData*>()),
                m_nActiveDataIndex(-1)
{
}

CDataManager::~CDataManager()
{
}

CDataManager* CDataManager::m_pInstance  = 0;

CDataManager* CDataManager::getInstance()
{
    if (m_pInstance == 0)
    {
        m_pInstance = new CDataManager;
    }
    return m_pInstance;
}

void CDataManager::deleteInstance()
{
    if (m_pInstance != 0)
    {
        delete m_pInstance;
        m_pInstance = 0;
    }
}

void CDataManager::appendData(CData *pData)
{
    if (pData != 0)
    {
        m_lstData.append(pData);
    }
}

CData* CDataManager::getData(int indx) const
{
    CData *pRet = 0;
    if ( (indx >= 0) && (indx < m_lstData.size()) )
    {
        pRet = m_lstData[indx];
    }
    return pRet;
}

void CDataManager::setActiveData(int indx)
{
    if (indx >= 0 && indx < m_lstData.size())
    {
        m_nActiveDataIndex = indx;
    }
    else
    {
        m_nActiveDataIndex = -1;
    }
}

CData* CDataManager::getActiveData() const
{
    CData *pRet = 0;
    if (m_nActiveDataIndex != -1)
    {
        pRet = m_lstData[m_nActiveDataIndex];
    }
    return pRet;
}

int CDataManager::getActiveDataIndex() const
{
    return m_nActiveDataIndex;
}

void CDataManager::removeData(int indx)
{
    if (indx >= 0 && indx < m_lstData.size())
    {
        delete m_lstData[indx];
        m_lstData.removeAt(indx);
    }
}

int CDataManager::count() const
{
    return m_lstData.size();
}
