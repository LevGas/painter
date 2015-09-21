#include "page.h"
#include "rectangle.h"
#include "circle.h"
#include "data_manager.h"

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QRectF>
#include <QHBoxLayout>
#include <QApplication>
#include <QDesktopWidget>


CPage::CPage(CSubject *pSubject, QWidget *parent)
            : QWidget(parent),
              CObserver(pSubject),
              m_nWidth(0),
              m_nHeight(0),
              m_nItemCount(0)

{
    m_pScene = new QGraphicsScene;
    CData *pData = dynamic_cast<CData*>(pSubject);
    Q_ASSERT(pData != 0);
    setPageSize(pData->getWidth(), pData->getHeight());
    drow_cord_system();
    m_pView = new QGraphicsView;
    m_pView->centerOn(m_nWidth / 2, m_nHeight / 2);
    m_pView->setScene(m_pScene);
    QHBoxLayout *pLayout = new QHBoxLayout;
    setLayout(pLayout);
    pLayout->addWidget(m_pView);
}

CPage::~CPage()
{
}

void CPage::drow_cord_system()
{
    m_pScene->addLine(0, m_nHeight / 2, m_nWidth, m_nHeight / 2);
    m_pScene->addLine(m_nWidth / 2, 0, m_nWidth / 2, m_nHeight);
}

void CPage::update()
{
    CData *pData = dynamic_cast<CData*>(m_pSubject);
    Q_ASSERT(pData != NULL);
    if (pData->count() > m_nItemCount)
    {
        CShape_Base *pShape = pData->lastShape();
        Q_ASSERT(pShape != 0);
        switch (pShape->type())
        {
        case CShape_Base::eRect:
        {
            CRectangle *pRect = dynamic_cast<CRectangle*>(pShape);
            Q_ASSERT(pRect != NULL);
            double x = pRect->get_X();
            double y = pRect->get_Y();
            QRectF rect(x, y, pRect->get_Width(), pRect->get_Height());
            QGraphicsItem* pRectItem = new QGraphicsRectItem(rect);
            m_pScene->addItem(pRectItem);
            ++m_nItemCount;
            break;
       }
       case CShape_Base::eCircle:
       {
            CCircle *pCircle = dynamic_cast<CCircle*>(pShape);
            Q_ASSERT(pCircle != NULL);
            double x = pCircle->get_X() - pCircle->getRadius();
            double y = pCircle->get_Y() - pCircle->getRadius();
            QRectF rect(x, y, 2 * pCircle->getRadius(), 2 * pCircle->getRadius());
            QGraphicsItem *pCircleItem = new QGraphicsEllipseItem(rect);
            m_pScene->addItem(pCircleItem);
            ++m_nItemCount;
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
        drow_cord_system();
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
