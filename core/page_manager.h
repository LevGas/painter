#ifndef CPAGE_MANAGER_H
#define CPAGE_MANAGER_H

#include <QList>

#include "page.h"

class CPageManager
{
public:
    ~CPageManager();

public:
    static CPageManager* getInstance();
    static void deleteInstance();

    CPage* getActivePage() const;
    void setActivePage(int indx);

    void appendPage(CPage* pPage);
    void removePage(int indx);
    int getActivePageIndex() const;

    int count() const;

private:
    CPageManager();
    CPageManager(const CPageManager&);
    CPageManager& operator=(const CPageManager&);

private:
    static CPageManager* m_pInstace;

private:
    QList<CPage*> m_lstPages;
    int m_nActivePage;

};

#endif // CPAGE_MANAGER_H
