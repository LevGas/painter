#include "create_square_command.h"
#include "shapes/square.h"
#include "data_manager.h"


CCreate_square_command::CCreate_square_command(CExpr *pX, CExpr *pY, CExpr *pW)
                    : CCreate_Command_Base()
{
    m_arrArgs.push_back( pX );
    m_arrArgs.push_back( pY );
    m_arrArgs.push_back( pW );
}


double CCreate_square_command::eval(CContext &context)
{
    if (m_arrArgs.size() < 3)
    {
        throw std::exception();
    }

    double x = m_arrArgs[0]->eval( context );
    double y = m_arrArgs[1]->eval( context );
    double w = m_arrArgs[2]->eval( context );

    CSquare *pSquare = new CSquare(x, y, w);
    CDataManager *pDataManager = CDataManager::getInstance();
    CData *pData = pDataManager->getActiveData();

    if (pData != 0)
    {
        pData->add(pSquare);
    }

    return 0.0;
}

