#ifndef CCLOSE_COMMAND_H
#define CCLOSE_COMMAND_H

#include "command_base.h"

#include <QStringList>

class CClose_Command : public CCommand_Base
{
public:
    CClose_Command();
    ~CClose_Command();

public:
    double eval( CContext& );

};

#endif // CCLOSE_COMMAND_H
