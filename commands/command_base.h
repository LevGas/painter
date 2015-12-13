#ifndef CCOMMAND_BASE_H
#define CCOMMAND_BASE_H

#include "vector"
#include "expresion.h"


typedef class CCommand_Base : public CExpr
{
public:
    CCommand_Base();
    virtual ~CCommand_Base();

public:
    virtual double eval( CContext& ) = 0;

} command;


#endif // CCOMMAND_BASE_H
// end of file
