#include <QVBoxLayout>
#include <exception>
#include "command_panel.h"
#include "command_parser.h"


CCommand_Panel::CCommand_Panel(QWidget *parent)
            : QWidget(parent)
{
    m_CurrentCommand = m_CommandBuffer.begin();

    QVBoxLayout *pMainLayout = new QVBoxLayout();
    setLayout(pMainLayout);

    m_pCommandsStory = new QTextEdit();
    m_pCommandsStory->setReadOnly(true);
    pMainLayout->addWidget(m_pCommandsStory);


    m_pCommandEditor = new CCommand_Editor(this);
    pMainLayout->addWidget(m_pCommandEditor);


    // set connections
    QObject::connect(m_pCommandEditor, SIGNAL(sigNewCommand(QString)), this, SLOT(get_command(QString)));
}

CCommand_Panel::~CCommand_Panel()
{
    parser::deleteInstance();
}

void CCommand_Panel::get_command(QString sCommand)
{
    parser* pParser = parser::getInstance();

    try
    {
        pParser->parse(sCommand);
    }
    catch( std::exception& err )
    {
        m_CommandBuffer.append(sCommand);
        m_CurrentCommand = m_CommandBuffer.end();
        m_pCommandsStory->append( QString("Error command ") + sCommand );
        return;
    }

    if (!sCommand.isEmpty() && !sCommand.isNull())
    {
        m_CommandBuffer.append(sCommand);
        m_CurrentCommand = m_CommandBuffer.end();
        m_pCommandsStory->append(sCommand);
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
            m_pCommandEditor->setText(sCommand);
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
                m_pCommandEditor->setText(sCommand);
            }
            else
            {
                m_pCommandEditor->clear();
            }
        }
        break;
    }
    default:
        break;
    }
}
