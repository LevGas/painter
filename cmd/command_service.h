#ifndef CCOMMAND_SERVICE_H
#define CCOMMAND_SERVICE_H

///////////////////////////////////////////////////
//  includes
///////////////////////////////////////////////////
#include "commands/command_base.h"
#include "commands/expresion.h"
#include "core/data.h"
#include <map>
#include <string>



typedef class CCommand_Service
{
public:
    ~CCommand_Service();

public:
    command* getCommand(const std::string & sCommand) const;

    void loadCommands();

public:
    static CCommand_Service* getInstance();
    static void deleteInstance();

private:
    CCommand_Service();
    CCommand_Service(const CCommand_Service &);
    CCommand_Service & operator=(const CCommand_Service &);

private:
    static CCommand_Service *m_pInstance;

private:
    std::map<std::string, command*> m_mapDataBasa;
    CContext* m_pContext;

    bool m_bLoaded;

} cmdService;

#endif // CCOMMAND_SERVICE_H
