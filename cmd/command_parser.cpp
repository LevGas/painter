#include "command_parser.h"
#include "command_service.h"

CCommand_Parser::CCommand_Parser()
{
}

CCommand_Parser::~CCommand_Parser()
{
    cmdService::deleteInstance();
}

parser* CCommand_Parser::m_pInstance = NULL;

parser* CCommand_Parser::getInstance()
{
    if (m_pInstance != NULL)
    {
        m_pInstance = new parser;
    }
    return m_pInstance;
}

void CCommand_Parser::deleteInstance()
{
    if (m_pInstance != NULL)
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

void CCommand_Parser::parse(const QString &sCommand)
{
    if (!sCommand.isEmpty())
    {
        QStringList lstCommand = splitCommand(sCommand);
        cmdService *pService = cmdService::getInstance();
        command *pCommand = pService->getCommand(lstCommand.first().toLower().toStdString());
        lstCommand.pop_front();
        if (pCommand != NULL)
            pCommand->exec(lstCommand);
    }
}


QStringList CCommand_Parser::splitCommand(const QString & sCommand)
{
    QStringList lstWords;
    QString::const_iterator it = sCommand.constBegin();
    QString sWord;
    while (it != sCommand.constEnd())
    {
        if ( !(it->isNull() || it->isSpace()) )
        {
            sWord.append(*it);
        }
        else
        {
            lstWords.append(sWord);
            sWord.clear();;
        }
        ++it;
    }
    if (!sWord.isEmpty())
        lstWords.append(sWord);
    return lstWords;
}
