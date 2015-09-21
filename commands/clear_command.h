#ifndef CCLEAR_COMMAND_H
#define CCLEAR_COMMAND_H

#include "command_base.h"

class CStringList;

class CClear_Command : public CCommand_Base
{
public:
    CClear_Command();
    ~CClear_Command();

    void exec(const QStringList &);

};

#endif // CCLEAR_COMMAND_H
