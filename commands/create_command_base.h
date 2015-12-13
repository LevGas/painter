#ifndef CCREATE_COMMAND_BASE_H
#define CCREATE_COMMAND_BASE_H

#include "command_base.h"


typedef class CCreate_Command_Base : public CCommand_Base
{
public:
    CCreate_Command_Base();
    virtual ~CCreate_Command_Base();

public:
    virtual double eval(CContext &) = 0;

protected:
    std::vector< CExpr* > m_arrArgs;

} createCommand;

#endif // CCREATE_COMMAND_BASE_H
