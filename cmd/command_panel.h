#ifndef CCOMMAND_PANEL_H
#define CCOMMAND_PANEL_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QStringList>
#include <QKeyEvent>

#include "line_edit.h"

typedef class CCommand_Panel : public QWidget
{
    Q_OBJECT
public:
    CCommand_Panel(QWidget *parent = 0);
    ~CCommand_Panel();

    void keyPressEvent(QKeyEvent *pKeyEvent);

public slots:
    void get_command(QString);

private:
    QTextEdit *m_pTextEdit;
    CLine_Edit *m_pLineEdit;
    QStringList m_CommandBuffer;
    QStringList::iterator m_CurrentCommand;

} panel;

#endif // CCOMMANDPANEL_H
