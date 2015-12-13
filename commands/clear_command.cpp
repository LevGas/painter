#include "clear_command.h"
#include "data_manager.h"

CClear_Command::CClear_Command()
                : CCommand_Base()
{
}

CClear_Command::~CClear_Command()
{
}

double CClear_Command::eval(CContext &/*args*/)
{
    CDataManager *pDataManager = CDataManager::getInstance();
    if (pDataManager != 0)
    {
        CData *pActiveData = pDataManager->getActiveData();
        if (pActiveData != 0)
        {
            pActiveData->clear();
        }
    }

    return 0.0;
}

