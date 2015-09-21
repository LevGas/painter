#include "create_circle_command.h"
#include "circle.h"
#include "data.h"
#include "data_manager.h"

CCreate_Circle_Command::CCreate_Circle_Command()
                        : CCreate_Command_Base()
{
}

CCreate_Circle_Command::~CCreate_Circle_Command()
{
}

void CCreate_Circle_Command::exec(const QStringList & args)
{
    if (args.size() >= 3)
    {
        bool bOk;
        double x = args[0].toDouble(&bOk);
        if (!bOk)
            return;
        double y = args[1].toDouble(&bOk);
        if (!bOk)
            return;
        double r = args[2].toDouble(&bOk);
        if (!bOk)
            return;
        CCircle *pCircle = new CCircle(x, y, r);
        CDataManager *pDataManager = CDataManager::getInstance();
        if (pDataManager != 0)
        {
            CData *pData = pDataManager->getActiveData();
            if(pData != 0)
            {
                pData->add(pCircle);
            }
        }
    }
}

