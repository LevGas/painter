#include "close_command.h"
#include "data_manager.h"
#include "page_manager.h"

CClose_Command::CClose_Command()
               : CCommand_Base()
{
}

CClose_Command::~CClose_Command()
{
}

void CClose_Command::exec(const QStringList &/*atgs*/)
{
    CDataManager *pDataManager = CDataManager::getInstance();
    if (pDataManager != 0)
    {
        int nActiveDataIndex = pDataManager->getActiveDataIndex();
        pDataManager->removeData(nActiveDataIndex);
    }
    CPageManager *pPageManager = CPageManager::getInstance();
    if (pPageManager != 0)
    {
        int nActivePageIndex = pPageManager->getActivePageIndex();
        pPageManager->removePage(nActivePageIndex);
    }
}

