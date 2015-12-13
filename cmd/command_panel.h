#ifndef CCOMMAND_PANEL_H
#define CCOMMAND_PANEL_H


////////////////////////////////////////////////
// includes
////////////////////////////////////////////////
#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QStringList>
#include <QKeyEvent>
#include "command_editor.h"


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
    QTextEdit* m_pCommandsStory;
    CCommand_Editor* m_pCommandEditor;
    QStringList m_CommandBuffer;
    QStringList::iterator m_CurrentCommand;

} panel;

#endif // CCOMMANDPANEL_H
