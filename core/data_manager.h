#ifndef CDATAMANAGER_H
#define CDATAMANAGER_H

#include "data.h"

#include <QList>

class CDataManager
{
public:
    ~CDataManager();

    static CDataManager* getInstance();
    static void deleteInstance();

    void appendData(CData* pData);
    CData* getData(int indx) const;

    void setActiveData(int indx);
    CData* getActiveData() const;
    int getActiveDataIndex() const;
    void removeData(int indx);

    int count() const;

private:
    CDataManager();
    CDataManager(const CDataManager &);
    CDataManager& operator=(const CDataManager&);

private:
    static CDataManager* m_pInstance;

private:
    QList<CData*> m_lstData;
    int m_nActiveDataIndex;

};

#endif // CDATAMANAGER_H
