#ifndef CPAGE_TAB_H
#define CPAGE_TAB_H

#include "page.h"

#include <QTabWidget>
#include <QList>

class CPageTab : public QTabWidget
{
    Q_OBJECT
public:
    CPageTab(QWidget *pParent = 0);
    ~CPageTab();

};

#endif // CPAGE_TAB_H
