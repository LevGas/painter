#include "command_editor.h"

CCommand_Editor::CCommand_Editor(QWidget* pParent)
        : QLineEdit(pParent)
{
    QObject::connect(this, SIGNAL(returnPressed()), this, SLOT(commandEdited()));
    QObject::connect(this, SIGNAL(returnPressed()), this, SLOT(clear()));
}


 void CCommand_Editor::commandEdited()
 {
     emit sigNewCommand( text() );;
 }
