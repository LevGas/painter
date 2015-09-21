#include "observer.h"
#include "subject.h"

CObserver::CObserver(CSubject *pSubject)
{
    setSubject(pSubject);
}

CObserver::~CObserver()
{
    m_pSubject->dettach(this);
}

CSubject* CObserver::getSubject() const
{
    return m_pSubject;
}

void CObserver::setSubject(CSubject *pSubject)
{
    m_pSubject = pSubject;
    if (m_pSubject != 0)
    {
        m_pSubject->attach(this);
    }
}
