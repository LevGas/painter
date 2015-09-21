#ifndef CEXIT_COMMAND_H
#define CEXIT_COMMAND_H

#include "command_base.h"

class QStringList;

class CExit_Command : public CCommand_Base
{
public:
    CExit_Command();
    ~CExit_Command();

    void exec(const QStringList &/*args*/);
};

#endif // CEXIT_COMMAND_H
