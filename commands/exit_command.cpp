#include "exit_command.h"

#include <QApplication>

CExit_Command::CExit_Command()
              : CCommand_Base()
{
}

CExit_Command::~CExit_Command()
{
}

void CExit_Command::exec(const QStringList &/*args*/)
{
    QApplication::quit();
}

