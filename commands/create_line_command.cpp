#include "create_line_command.h"
#include "shapes/line.h"
#include "data_manager.h"
#include <QDebug>


CCreate_Line_command::CCreate_Line_command(CExpr *pX1 , CExpr *pY1, CExpr *pX2, CExpr *pY2)
                    : CCreate_Command_Base()
{
    m_arrArgs.push_back( pX1 );
    m_arrArgs.push_back( pY1 );
    m_arrArgs.push_back( pX2 );
    m_arrArgs.push_back( pY2 );
}


double CCreate_Line_command::eval( CContext& context )
{
    if (m_arrArgs.size() < 4)
    {
        throw std::exception();
    }

    double x1 = m_arrArgs[0]->eval( context );
    double y1 = m_arrArgs[1]->eval( context );
    double x2 = m_arrArgs[2]->eval( context );
    double y2 = m_arrArgs[3]->eval( context );

 //   qDebug() << x1 << " " << y1 << " " << x2 << " " << y2;

    CLine *pLine = new CLine(x1, y1, x2, y2);

    CDataManager *pDataManager = CDataManager::getInstance();
    CData *pData = pDataManager->getActiveData();

    if (pData != 0)
        pData->add(pLine);

    return 0.0;
}
