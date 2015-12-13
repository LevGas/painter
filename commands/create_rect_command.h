#ifndef CCREATE_RECT_COMMAND_H
#define CCREATE_RECT_COMMAND_H

#include "create_command_base.h"

typedef class CCreate_Rect_Command : public CCreate_Command_Base
{
public:
    CCreate_Rect_Command(CExpr* pX, CExpr* pY, CExpr* pW, CExpr* pH );
    ~CCreate_Rect_Command();

public:
    virtual double eval(CContext& context);

} createRect;


#endif // CCREATE_RECT_COMMAND_H
// end of file
