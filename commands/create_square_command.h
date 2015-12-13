#ifndef CCREATE_SQUARE_COMMAND_H
#define CCREATE_SQUARE_COMMAND_H


#include "create_command_base.h"


typedef class CCreate_square_command : public CCreate_Command_Base
{
public:
    CCreate_square_command( CExpr* pX, CExpr* pY, CExpr* pW );

public:
    virtual double eval( CContext& context );

} createSquare;

#endif // CCREATE_SQUARE_COMMAND_H
