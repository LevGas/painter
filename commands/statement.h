#ifndef STATEMENT_H
#define STATEMENT_H

#include "expresion.h"
#include "command_base.h"
#include <vector>



class CStatement
{
public:
    CStatement()
    {}

    virtual ~CStatement()
    {}

public:
    virtual void eval( CContext& context ) = 0;


protected:
    std::vector<CExpr*> m_arrExpr;

};


class CLoop : public CStatement
{
public:
    CLoop( int nCount, const std::vector<CExpr*> arrExpr  )
        : CStatement(),
          m_nCount( nCount )
    {
        m_arrExpr = arrExpr;
    }

    virtual ~CLoop()
    {}

public:
    virtual void eval( CContext& context )
    {
        for ( int nIter = 0; nIter < m_nCount; ++nIter )
        {
            for ( int nPos = 0; nPos < m_arrExpr.size(); ++nPos )
            {
                CExpr* pExp = m_arrExpr[nPos];
                pExp->eval( context );
            }
        }
    }


private:
    const int m_nCount;

};







#endif // STATEMENT_H

