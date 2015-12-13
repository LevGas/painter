#include "Painter.h"
#include "cmd/command_service.h"
#include "core/page.h"
#include "commands/data_manager.h"

#include <QDockWidget>
#include <QTabBar>
#include <QApplication>
#include <QDesktopWidget>


CPainter::CPainter(QWidget *parent)
    : QMainWindow(parent)
{
    m_pMainWidget = new QWidget(this);
    setCentralWidget(m_pMainWidget);
    m_pMainLayout = new QVBoxLayout(m_pMainWidget);
    m_pMainWidget->setLayout(m_pMainLayout);

    create_Command_Panel();
    create_Page_Tab();

    cmdService *pService = cmdService::getInstance();
    pService->loadCommands();
}

CPainter::~CPainter()
{
    CDataManager::deleteInstance();
    CPageManager::deleteInstance();
}

void CPainter::create_Command_Panel()
{
    m_pPanel = new panel(m_pMainWidget);
    QDockWidget* dw = new QDockWidget("cmd", this);
    dw->setWidget(m_pPanel);
    addDockWidget(Qt::BottomDockWidgetArea, dw);
}

void CPainter::create_Page_Tab()
{
    m_pPageTab = new CPageTab(m_pMainWidget);
    m_pMainLayout->addWidget(m_pPageTab);
    m_pMainLayout->setAlignment(m_pPageTab, Qt::AlignCenter);

    const bool b = QObject::connect(m_pPageTab->tabBar(), SIGNAL(currentChanged(int)), this, SLOT(page_changed(int)));
    Q_ASSERT(b);
    create_New_Page(0);
}

void CPainter::page_changed(int indx)
{
    if (indx == -1)
    {
        return;
    }
    if (indx >= 0 && indx < m_pPageTab->tabBar()->count() - 1)
    {
        set_Active_Page(indx);
    }
    else if (indx == m_pPageTab->tabBar()->count() - 1)
    {
        create_New_Page(indx);
    }
}

void CPainter::create_New_Page(int indx)
{
    CData* pData = new CData();
    QSize ds = QApplication::desktop()->size();
    pData->setPageSize(ds.width(), ds.height());

    CDataManager* pDataManager = CDataManager::getInstance();
    pDataManager->appendData(pData);
    pDataManager->setActiveData(pDataManager->count() - 1);

    CPage *pPage = new CPage(pDataManager->getActiveData());
    CPageManager* pPageManager = CPageManager::getInstance();
    pPageManager->setActivePage(pPageManager->count() - 1);
    pPageManager->appendPage(pPageManager->getActivePage());

    m_pPageTab->insertTab(indx, pPage, "Page_" + QString::number(indx + 1));
    m_pPageTab->setCurrentIndex(indx);
}

void CPainter::set_Active_Page(int indx)
{
    CPageManager *pPageManager = CPageManager::getInstance();
    pPageManager->setActivePage(indx);

    CDataManager *pDataManager = CDataManager::getInstance();
    pDataManager->setActiveData(indx);
}
