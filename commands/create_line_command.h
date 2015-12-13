#ifndef CCREATE_LINE_COMMAND_H
#define CCREATE_LINE_COMMAND_H

#include "create_command_base.h"


typedef class CCreate_Line_command : public CCreate_Command_Base
{
public:
    CCreate_Line_command( CExpr* pX1, CExpr* pY1, CExpr* pX2, CExpr* pY2 );

public:
    virtual double eval( CContext& );

} createLine;

#endif // CCREATE_LINE_COMMAND_H
