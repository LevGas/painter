#ifndef CCOMMAND_EDITOR_H
#define CCOMMAND_EDITOR_H


////////////////////////////////////////
//  includes
////////////////////////////////////////
#include <QLineEdit>
#include <QString>


class CCommand_Editor : public QLineEdit
{
    Q_OBJECT
public:
    //  constructor
    CCommand_Editor(QWidget *pParent = 0);

private slots:
    //
    //
    //
    void commandEdited();

signals:
    //
    //
    //
    void sigNewCommand(QString);

};


#endif // CCOMMAND_EDITOR_H
// end of file
