#ifndef COBSERVER_H
#define COBSERVER_H

class CSubject;

class CObserver
{
public:
    CObserver(CSubject *pSubject = 0);
    virtual ~CObserver();
    virtual void update() = 0;

    void setSubject(CSubject *pSubject);
    CSubject* getSubject() const;

protected:
    CSubject *m_pSubject;
};

#endif // COBSERVER_H
