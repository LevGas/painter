#ifndef PAINTER_H
#define PAINTER_H

#include "cmd/command_panel.h"
#include "commands/data_manager.h"
#include "core/page_manager.h"
#include "page_tab.h"

#include <QMainWindow>
#include <QVBoxLayout>

class CPainter : public QMainWindow
{
    Q_OBJECT

public:
    explicit CPainter(QWidget *parent = 0);
    ~CPainter();

private:
    void create_Command_Panel();
    void create_Page_Tab();
    void create_New_Page(int indx);
    void set_Active_Page(int indx);

public slots:
    void page_changed(int indx);

private:
    QWidget *m_pMainWidget;
    QVBoxLayout *m_pMainLayout;
    panel *m_pPanel;
    CPageTab *m_pPageTab;

};

#endif // PAINTER_H
