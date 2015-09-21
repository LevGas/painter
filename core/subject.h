#ifndef CSUBJECT_H
#define CSUBJECT_H

#include <list>

class CObserver;

class CSubject
{
public:
    CSubject();
    virtual ~CSubject()
    {}

    void notify();

    void attach(CObserver* pObserver);
    void dettach(CObserver* pObserver);

protected:
    std::list<CObserver*> m_lstObservers;

};

#endif // CSUBJECT_H
