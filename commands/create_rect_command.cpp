#include "create_rect_command.h"
#include "shapes/rectangle.h"
#include "data_manager.h"


CCreate_Rect_Command::CCreate_Rect_Command(CExpr *pX, CExpr *pY, CExpr *pW, CExpr *pH)
                : CCreate_Command_Base()
{
    m_arrArgs.push_back( pX );
    m_arrArgs.push_back( pY );
    m_arrArgs.push_back( pW );
    m_arrArgs.push_back( pH );
}


CCreate_Rect_Command::~CCreate_Rect_Command()
{
}


double CCreate_Rect_Command::eval( CContext & context )
{
    if (m_arrArgs.size() < 4)
    {
        throw std::exception();
    }

    double x = m_arrArgs[0]->eval( context );
    double y = m_arrArgs[1]->eval( context );
    double w = m_arrArgs[2]->eval( context );
    double h = m_arrArgs[3]->eval( context );


    CRectangle *pRect = new CRectangle(x, y, w, h);
    CDataManager *pDataManager = CDataManager::getInstance();
    CData *pData = pDataManager->getActiveData();
    if (pData != 0)
        pData->add(pRect);


    return 0.0;
}

