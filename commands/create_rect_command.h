#ifndef CCREATE_RECT_COMMAND_H
#define CCREATE_RECT_COMMAND_H

#include "create_command_base.h"

#include <QStringList>

typedef class CCreate_Rect_Command : public CCreate_Command_Base
{
public:
    CCreate_Rect_Command();
    ~CCreate_Rect_Command();

    void exec(const QStringList & args);

} createRect;

#endif // CCREATE_RECT_COMMAND_H
