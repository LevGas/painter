#ifndef CCREATE_CIRCLE_COMMAND_H
#define CCREATE_CIRCLE_COMMAND_H

#include "create_command_base.h"
#include <vector>

typedef class CCreate_Circle_Command : public CCreate_Command_Base
{
public:
    CCreate_Circle_Command( CExpr* pX, CExpr* pY, CExpr* pR );
    ~CCreate_Circle_Command();

public:
    virtual double eval(CContext& context);

} createCircle;

#endif // CCREATE_CIRCLE_COMMAND_H
