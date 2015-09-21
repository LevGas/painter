#include <QVBoxLayout>

#include "command_panel.h"
#include "command_parser.h"


CCommand_Panel::CCommand_Panel(QWidget *parent)
            : QWidget(parent)
{
    m_CurrentCommand = m_CommandBuffer.begin();

    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
    setLayout(pMainLayout);
    m_pTextEdit = new QTextEdit(this);
    pMainLayout->addWidget(m_pTextEdit);
    m_pTextEdit->setReadOnly(true);
    m_pLineEdit = new CLine_Edit(this);
    QObject::connect(m_pLineEdit, SIGNAL(text_edited(QString)), this, SLOT(get_command(QString)));
    pMainLayout->addWidget(m_pLineEdit);
}

CCommand_Panel::~CCommand_Panel()
{
    parser::deleteInstance();
}

void CCommand_Panel::get_command(QString sCommand)
{
    parser *pParser = parser::getInstance();
    pParser->parse(sCommand);
    if (!sCommand.isEmpty() && !sCommand.isNull())
    {
        m_CommandBuffer.append(sCommand);
        m_CurrentCommand = m_CommandBuffer.end();
        m_pTextEdit->append(sCommand);
    }
}

void CCommand_Panel::keyPressEvent(QKeyEvent *pKeyEvent)
{
    switch (pKeyEvent->key())
    {
    case Qt::Key_Up:
    {
        if (m_CurrentCommand != m_CommandBuffer.begin())
        {
            --m_CurrentCommand;
            QString sCommand = *m_CurrentCommand;
            m_pLineEdit->setText(sCommand);
        }
        break;
    }
    case Qt::Key_Down:
    {
        if (m_CurrentCommand != m_CommandBuffer.end())
        {
            ++m_CurrentCommand;
            if (m_CurrentCommand != m_CommandBuffer.end())
            {
                QString sCommand = *m_CurrentCommand;
                m_pLineEdit->setText(sCommand);
            }
            else
            {
                m_pLineEdit->clear();
            }
        }
        break;
    }
    default:
        break;
    }
}
