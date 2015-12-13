#ifndef COBSERVER_H
#define COBSERVER_H

class CSubject;

class CObserver
{
public:
    CObserver();
    virtual ~CObserver();

    virtual void update() = 0;

};

#endif // COBSERVER_H
