#ifndef CCREATE_CIRCLE_COMMAND_H
#define CCREATE_CIRCLE_COMMAND_H

#include "create_command_base.h"

#include <QStringList>

typedef class CCreate_Circle_Command : public CCreate_Command_Base
{
public:
    CCreate_Circle_Command();
    ~CCreate_Circle_Command();

    void exec(const QStringList & args);

} createCircle;

#endif // CCREATE_CIRCLE_COMMAND_H
