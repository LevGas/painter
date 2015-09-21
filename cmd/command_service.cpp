#include "command_service.h"
#include "create_command_base.h"
#include "create_rect_command.h"
#include "create_circle_command.h"
#include "clear_command.h"
#include "close_command.h"
#include "exit_command.h"

CCommand_Service::CCommand_Service()
            : m_bLoaded(false)
{
}

CCommand_Service::~CCommand_Service()
{
    std::map<std::string, CCommand_Base*>::iterator it = m_mapDataBasa.begin();
    while (it != m_mapDataBasa.end())
    {
        delete (*it).second;
        m_mapDataBasa.erase(it);
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
        pRet = (*it).second;
    return pRet;
}

void CCommand_Service::loadCommands()
{
    if (!m_bLoaded)
    {
        m_bLoaded = true;

        command *pCreateRect = new createRect;
        m_mapDataBasa["createrect"] = pCreateRect;

        command *pCreateCircle  = new createCircle;
        m_mapDataBasa["createcircle"] = pCreateCircle;

        command *pClear = new CClear_Command;
        m_mapDataBasa["clear"] = pClear;

        command *pClose = new CClose_Command;
        m_mapDataBasa["close"] = pClose;

        command *pExit = new CExit_Command;
        m_mapDataBasa["exit"] = pExit;
        // TODO
    }
}
