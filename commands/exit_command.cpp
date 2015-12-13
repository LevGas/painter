#include "exit_command.h"

#include <QApplication>

CExit_Command::CExit_Command()
              : CCommand_Base()
{
}

CExit_Command::~CExit_Command()
{
}

double CExit_Command::eval(CContext &)
{
    QApplication::quit();

    return 0.0;
}

