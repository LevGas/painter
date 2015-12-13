#ifndef EXPRESION_H
#define EXPRESION_H

#include <string>
#include <QMap>


class CVarExpr;
class CConstExpr;


class CContext
{
public:
    CContext()
        : m_mapValues()
    {
        m_mapValues.clear();
    }

    ~CContext()
    {}

public:
    double assigne( CVarExpr* pVariable, double fValue );
    double lookUp( const std::string& sName );


private:
    QMap<std::string, double> m_mapValues;

};




///////////////////////////////////////////
//  base expresion
///////////////////////////////////////////
class CExpr
{
public:
    CExpr()
    {}

    virtual ~CExpr()
    {}

public:
    virtual double eval( CContext& ) = 0;

};


///////////////////////////////////////////
// variable expresion
///////////////////////////////////////////
class CVarExpr : public CExpr
{
public:
    CVarExpr( const std::string& sName )
        : m_sName(sName)
    {}

    virtual ~CVarExpr()
    {}

public:
    virtual double eval( CContext& context )
    {
        return context.lookUp( m_sName );
    }


    std::string getName() const
    {
        return m_sName;
    }


private:
    std::string m_sName;

};


///////////////////////////////////////////
// const expresion
///////////////////////////////////////////
class CConstExpr : public CExpr
{
public:
    CConstExpr( double fValue )
        : m_fValue( fValue )
    {}

    virtual ~CConstExpr()
    {}


public:
    virtual double eval( CContext& )
    {
        return m_fValue;
    }

private:
    const double m_fValue;

};


class CAddExpr : public CExpr
{
public:
    CAddExpr( CExpr* pOp1, CExpr* pOp2 )
        : m_pOp1( pOp1 ),
          m_pOp2( pOp2 )
    {}

    virtual ~CAddExpr()
    {}

public:
    virtual double eval( CContext& context )
    {
        return ( m_pOp1->eval( context ) + m_pOp2->eval( context ) );
    }

private:
    CExpr* m_pOp1;
    CExpr* m_pOp2;

};


class CSubExpr : public CExpr
{
public:
    CSubExpr( CExpr* pOp1, CExpr* pOp2 )
        : m_pOp1( pOp1 ),
          m_pOp2( pOp2 )
    {}

    virtual ~CSubExpr()
    {}

public:
    virtual double eval( CContext& context )
    {
        return ( m_pOp1->eval( context ) - m_pOp2->eval( context ) );
    }

private:
    CExpr* m_pOp1;
    CExpr* m_pOp2;

};


class CAssignExpr : public CExpr
{
public:
    CAssignExpr( CVarExpr* pOp1, CExpr* pOp2 )
        : m_pOp1( pOp1 ),
          m_pOp2( pOp2 )
    {}

    virtual ~CAssignExpr()
    {}

public:
    virtual double eval( CContext& context )
    {
        return ( context.assigne( m_pOp1, m_pOp2->eval( context ) ) );
    }

private:
    CVarExpr* m_pOp1;
    CExpr* m_pOp2;

};



#endif // EXPRESION_H
// end of file
