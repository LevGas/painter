#include "page.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QRectF>
#include <QHBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>


CPage::CPage(CData *pData, QWidget *parent)
            : QWidget(parent),
              CObserver(),
              m_pData(pData),
              m_nWidth(0),
              m_nHeight(0),
              m_nItemCount(0)

{
    m_pCoordConvertor = new CCordConvertor;

    m_pData->attach(this);

    m_pScene = new QGraphicsScene;
    setPageSize(m_pData->getWidth(), m_pData->getHeight());

    draw_cord_system();
    m_pView = new QGraphicsView;
    m_pView->centerOn(m_nWidth / 2, m_nHeight / 2);
    m_pView->setScene(m_pScene);
    QHBoxLayout *pLayout = new QHBoxLayout;
    setLayout(pLayout);
    pLayout->addWidget(m_pView);
}

CPage::~CPage()
{
    m_pData->dettach(this);
}

void CPage::draw_cord_system()
{
    m_pScene->addLine(0, m_nHeight / 2, m_nWidth, m_nHeight / 2);
    m_pScene->addLine(m_nWidth / 2, 0, m_nWidth / 2, m_nHeight);
}


void CPage::draw_rect(CRectangle *pRect)
{
    double x =  m_pCoordConvertor->convert_X( pRect->get_X() );
    double y =  m_pCoordConvertor->convert_Y( pRect->get_Y() );

    QRectF rect(x, y, pRect->get_Width(), pRect->get_Height());
    QGraphicsItem* pRectItem = new QGraphicsRectItem(rect);
    m_pScene->addItem(pRectItem);
    ++m_nItemCount;
}


void CPage::draw_circle(CCircle *pCircle)
{
    double x = m_pCoordConvertor->convert_X( pCircle->get_X() ) - pCircle->getRadius();
    double y = m_pCoordConvertor->convert_Y( pCircle->get_Y() ) - pCircle->getRadius();

    QRectF rect(x, y, 2 * pCircle->getRadius(), 2 * pCircle->getRadius());
    QGraphicsItem *pCircleItem = new QGraphicsEllipseItem(rect);
    m_pScene->addItem(pCircleItem);
    ++m_nItemCount;
}


void CPage::draw_square(CSquare *pSquare)
{
    double x = m_pCoordConvertor->convert_X( pSquare->get_X() );
    double y = m_pCoordConvertor->convert_Y( pSquare->get_Y() );

    QRectF rect(x, y, pSquare->get_Width(), pSquare->get_Width());
    QGraphicsItem* pRectItem = new QGraphicsRectItem(rect);
    m_pScene->addItem(pRectItem);
    ++m_nItemCount;
}


void CPage::draw_line(CLine *pLine)
{
    double x1 = m_pCoordConvertor->convert_X( pLine->get_X() );
    double y1 = m_pCoordConvertor->convert_Y( pLine->get_Y() );
    double x2 = m_pCoordConvertor->convert_X( pLine->get_Dest_X() );
    double y2 = m_pCoordConvertor->convert_Y( pLine->get_Dest_Y() );

//    qDebug() << x1 << " " << y1 << " " << x2 << " " << y2;

    QLineF line(x1, y1, x2, y2);
    QGraphicsItem *pLineItem = new QGraphicsLineItem(line);
    m_pScene->addItem(pLineItem);
    ++m_nItemCount;
}


void CPage::update()
{   
    if (m_pData->count() > m_nItemCount)
    {
        CShape_Base *pShape = m_pData->lastShape();
        Q_ASSERT(pShape != 0);
        switch (pShape->type())
        {
        case CShape_Base::eRect:
        {
            CRectangle *pRect = static_cast<CRectangle*>(pShape);
            draw_rect(pRect);

            break;
       }
       case CShape_Base::eCircle:
       {
            CCircle *pCircle = static_cast<CCircle*>(pShape);
            draw_circle(pCircle);

            break;
        }
        case CShape_Base::eSquare:
        {
            CSquare *pSquare = static_cast<CSquare*>(pShape);
            draw_square(pSquare);

            break;
        }
        case CShape_Base::eLine:
        {
            CLine *pLine = static_cast<CLine*>(pShape);
            draw_line(pLine);

            break;
        }
        default:
            break;
        }
    }
    else
    {
        m_pScene->clear();
        m_nItemCount = 0;
        draw_cord_system();
    }
}

void CPage::setPageSize(int w, int h)
{
    if (h > 0)
        m_nHeight = h;
    else
        m_nHeight = 0;

    if (w > 0)
        m_nWidth = w;
    else
        m_nWidth = 0;

    m_pScene->setSceneRect(0, 0, m_nWidth, m_nHeight);

    m_pCoordConvertor->setSize(m_nWidth, m_nHeight);
    m_pCoordConvertor->setOrigin(m_nWidth / 2, m_nHeight / 2);
}


void CPage::remove_Shape(int indx)
{
    QList<QGraphicsItem*> lstItems = m_pScene->items();
    if (indx >= 0 && indx < lstItems.size())
    {
        m_pScene->removeItem(lstItems[indx]);
        --m_nItemCount;
    }
}
