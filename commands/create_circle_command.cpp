#include "create_circle_command.h"
#include "shapes/circle.h"
#include "core/data.h"
#include "data_manager.h"

CCreate_Circle_Command::CCreate_Circle_Command(CExpr *pX, CExpr *pY, CExpr *pR)
                        : CCreate_Command_Base()
{
    m_arrArgs.push_back( pX );
    m_arrArgs.push_back( pY );
    m_arrArgs.push_back( pR );
}


CCreate_Circle_Command::~CCreate_Circle_Command()
{
}


double CCreate_Circle_Command::eval( CContext& context )
{
    if (m_arrArgs.size() >= 3)
    {
        double x = m_arrArgs[0]->eval( context );
        double y = m_arrArgs[1]->eval( context );
        double r = m_arrArgs[2]->eval( context );

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
    else
    {
        throw std::exception();
    }

    return 0.0;
}

