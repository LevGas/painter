#include "line_edit.h"

CLine_Edit::CLine_Edit(QWidget *parent)
        : QLineEdit(parent)
{
    QObject::connect(this, SIGNAL(returnPressed()), this, SLOT(return_pressed()));
    QObject::connect(this, SIGNAL(returnPressed()), this, SLOT(clear()));
}

void CLine_Edit::return_pressed()
{
    emit text_edited(text());
}

