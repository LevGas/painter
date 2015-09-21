#ifndef CCOMMAND_SERVICE_H
#define CCOMMAND_SERVICE_H

#include "command_base.h"
#include "data.h"

#include <map>
#include <string>

typedef class CCommand_Service
{
public:
    ~CCommand_Service();
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
    bool m_bLoaded;

} cmdService;

#endif // CCOMMAND_SERVICE_H
