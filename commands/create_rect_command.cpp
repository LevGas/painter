#include "create_command_base.h"
#include "create_rect_command.h"
#include "rectangle.h"
#include "data_manager.h"

CCreate_Rect_Command::CCreate_Rect_Command()
                : CCreate_Command_Base()
{

}

CCreate_Rect_Command::~CCreate_Rect_Command()
{
}

void CCreate_Rect_Command::exec(const QStringList & args)
{
    if (args.size() < 4)
        return;
    bool bOk;
    double x = args[0].toDouble(&bOk);
    if (!bOk)
        return;
    double y = args[1].toDouble(&bOk);
    if (!bOk)
        return;
    double w = args[2].toDouble(&bOk);
    if (!bOk)
        return;
    double h = args[3].toDouble(&bOk);
    if (!bOk)
        return;
    CRectangle *pRect = new CRectangle(x, y, w, h);
    CDataManager *pDataManager = CDataManager::getInstance();
    CData *pData = pDataManager->getActiveData();
    if (pData != 0)
        pData->add(pRect);
}

