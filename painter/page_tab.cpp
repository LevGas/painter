#include "page_tab.h"

#include <QTabBar>

CPageTab::CPageTab(QWidget *pParent)
            : QTabWidget(pParent)
{
    tabBar()->addTab("+");
}

CPageTab::~CPageTab()
{
}


