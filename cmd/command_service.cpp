#include "command_service.h"
#include "commands/create_command_base.h"
#include "commands/create_rect_command.h"
#include "commands/create_circle_command.h"
#include "commands/clear_command.h"
#include "commands/close_command.h"
#include "commands/exit_command.h"
#include "commands/create_square_command.h"
#include "commands/create_line_command.h"

CCommand_Service::CCommand_Service()
            : m_bLoaded(false)
{
}

CCommand_Service::~CCommand_Service()
{
    std::map<std::string, CCommand_Base*>::iterator it = m_mapDataBasa.begin();
    while (it != m_mapDataBasa.end())
    {
        CCommand_Base* pCommand = (*it++).second;
        delete pCommand;
    }
}

CCommand_Service* CCommand_Service::m_pInstance = NULL;

CCommand_Service* CCommand_Service::getInstance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new CCommand_Service;
    }
    return m_pInstance;
}

void CCommand_Service::deleteInstance()
{
    if (m_pInstance != NULL)
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

command *CCommand_Service::getCommand(const std::string & sCommand) const
{
    command *pRet = NULL;
    std::map<std::string, command*>::const_iterator it = m_mapDataBasa.find(sCommand);
    if (it != m_mapDataBasa.end())
    {
        pRet = (*it).second;
    }

    return pRet;
}


void CCommand_Service::loadCommands()
{
    if (!m_bLoaded)
    {
        m_bLoaded = true;

        command *pClear = new CClear_Command;
        m_mapDataBasa["clear"] = pClear;

        command *pClose = new CClose_Command;
        m_mapDataBasa["close"] = pClose;

        command *pExit = new CExit_Command;
        m_mapDataBasa["exit"] = pExit;
    }
}
