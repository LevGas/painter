#include "expresion.h"


double CContext::assigne( CVarExpr* pVariable, double fValue )
{
    m_mapValues[ pVariable->getName() ] = fValue;

    return fValue;
}


double CContext::lookUp( const std::string& sName )
{
    if ( !m_mapValues.contains( sName ) )
        return 0.0;

    return m_mapValues[ sName ];
}
