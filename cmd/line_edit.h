#ifndef CLINE_EDIT_H
#define CLINE_EDIT_H

#include <QLineEdit>
#include <QString>


class CLine_Edit : public QLineEdit
{
    Q_OBJECT
public:
    CLine_Edit(QWidget *parent = 0);

public slots:
    void return_pressed();

signals:
    void text_edited(QString);
};

#endif // CLINE_EDIT_H
