#ifndef CCOMMAND_BASE_H
#define CCOMMAND_BASE_H

#include "data.h"

#include <QStringList>

typedef class CCommand_Base
{
public:
    CCommand_Base();
    virtual ~CCommand_Base();

    virtual void exec(const QStringList & args) = 0;

} command;

#endif // CCOMMAND_BASE_H
