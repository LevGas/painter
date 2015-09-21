#include "subject.h"
#include "observer.h"

CSubject::CSubject()
{
}

void CSubject::notify()
{
    std::list<CObserver*>::iterator it = m_lstObservers.begin();
    while(it != m_lstObservers.end())
    {
        (*it)->update();
        ++it;
    }
}

void CSubject::attach(CObserver *pObserver)
{
    m_lstObservers.push_back(pObserver);
}

void CSubject::dettach(CObserver *pObserver)
{
    m_lstObservers.remove(pObserver);
}

