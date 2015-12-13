#include "command_parser.h"
#include "command_service.h"
#include "commands/statement.h"
#include "commands/create_command_base.h"
#include "commands/create_rect_command.h"
#include "commands/create_circle_command.h"
#include "commands/clear_command.h"
#include "commands/close_command.h"
#include "commands/exit_command.h"
#include "commands/create_square_command.h"
#include "commands/create_line_command.h"
#include <exception>


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
    if (m_pInstance == NULL)
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

void CCommand_Parser::parse(const QString &sLine)
{
    CContext context;

    QString sCommand = sLine.toLower();

    if (!sCommand.isEmpty())
    {
        QStringList lstToken = splitCommand(sCommand);
        QString sToken = lstToken.first();
        lstToken.pop_front();

        if ( sToken == "loop" )
        {
            if ( lstToken.isEmpty() )
                return;

            sToken = lstToken.first();
            lstToken.pop_front();

            bool bOk;
            int nCount = sToken.toInt( &bOk );
            if ( !bOk )
                return;

            CExpr* pExp = parseExpresion( lstToken );
            if ( pExp == NULL )
                return;

            std::vector<CExpr*> arrArgs;
            arrArgs.push_back( pExp );
            CLoop* pLoop = new CLoop( nCount,  arrArgs );
            pLoop->eval( m_context );
        }
        else if ( isShape( sToken ) )
        {
            lstToken.prepend( sToken );
            CExpr* pShape = parseShape( lstToken );

            if ( pShape == NULL )
                throw std::exception();

            pShape->eval( m_context );
        }
        else if ( isCommand( sToken ) )
        {
            lstToken.prepend( sToken );
            CExpr* pCommand = parseCommand( lstToken );

            if ( pCommand == NULL )
                throw std::exception();

            pCommand->eval( m_context );
        }
        else if ( isVarible( sToken ) )
        {
            lstToken.prepend( sToken );
            CExpr* pVar = parseExpresion( lstToken );

            if ( pVar == NULL )
                throw std::exception();

            pVar->eval( m_context );
        }
        else
        {
            throw std::exception();
        }
    }
}


CExpr* CCommand_Parser::parseExpresion( QStringList& sTokenList )
{
    if ( sTokenList.isEmpty() )
        return NULL;

    CExpr* pOp1 = NULL;

    while ( !sTokenList.isEmpty() )
    {
        QString sToken = sTokenList.first();
        sTokenList.pop_front();

        if ( isShape( sToken ) )
        {
            sTokenList.prepend( sToken );
            pOp1 = parseShape( sTokenList );
        }
        else if ( isVarible( sToken ) )
        {
            CExpr* pExp = new CVarExpr( sToken.toStdString() );
            pOp1 = pExp;
        }
        else if ( isDigit( sToken ) )
        {
            CExpr* pExp = new CConstExpr( sToken.toDouble() );
            pOp1 = pExp;
        }
        else if ( isAssigne( sToken ) )
        {
            if ( pOp1 == NULL )
                throw std::exception();

            CVarExpr* pVar = dynamic_cast<CVarExpr*>(pOp1);
            if ( pVar != NULL )
            {
                CExpr* pExp = new CAssignExpr( pVar, parseExpresion( sTokenList ) );
                pOp1 = pExp;
            }
            else
            {
                throw std::exception();
            }
        }
        else if ( isPlus( sToken ) )
        {
            if ( pOp1 == NULL )
                throw std::exception();

            CExpr* pExp = new CAddExpr( pOp1, parseExpresion( sTokenList ) );
            pOp1 = pExp;
        }
        else if ( isMinus( sToken ) )
        {
            if ( pOp1 == NULL )
                throw std::exception();

            CExpr* pExp = new CSubExpr( pOp1, parseExpresion( sTokenList ) );
            pOp1 = pExp;
        }
    }

    if ( pOp1 == NULL )
        throw std::exception();

    return pOp1;
}


CExpr* CCommand_Parser::parseShape( QStringList& sTokenList )
{
    QString sShape = sTokenList.first();
    sTokenList.pop_front();

    QList<QStringList> lstArgs;
    QStringList lstArg;
    while ( !sTokenList.isEmpty() )
    {
        QString sToken = sTokenList.first();
        sTokenList.pop_front();

        if ( sToken == ";" )
        {
            lstArgs.append( lstArg );
            lstArg.clear();
        }
        else
        {
            lstArg.append( sToken );
        }
    }
    lstArgs.append( lstArg );

    if ( sShape == "rect" )
    {
        if ( lstArgs.size() == 4 )
        {
            CExpr* pExp1 = parseExpresion( lstArgs[0] );
            CExpr* pExp2 = parseExpresion( lstArgs[1] );
            CExpr* pExp3 = parseExpresion( lstArgs[2] );
            CExpr* pExp4 = parseExpresion( lstArgs[3] );

            if ( pExp1 && pExp2 && pExp3 && pExp4 )
                return new CCreate_Rect_Command( pExp1, pExp2, pExp3, pExp4 );
            else
                 throw std::exception();
        }
    }
    else if ( sShape == "squer" )
    {
        if ( lstArgs.size() == 3 )
        {
            CExpr* pExp1 = parseExpresion( lstArgs[0] );
            CExpr* pExp2 = parseExpresion( lstArgs[1] );
            CExpr* pExp3 = parseExpresion( lstArgs[2] );

            if ( pExp1 && pExp2 && pExp3 )
                return new CCreate_square_command( pExp1, pExp2, pExp3 );
            else
                 throw std::exception();
        }
    }
    else if ( sShape == "line" )
    {
        if ( lstArgs.size() == 4 )
        {
            CExpr* pExp1 = parseExpresion( lstArgs[0] );
            CExpr* pExp2 = parseExpresion( lstArgs[1] );
            CExpr* pExp3 = parseExpresion( lstArgs[2] );
            CExpr* pExp4 = parseExpresion( lstArgs[3] );

            if ( pExp1 && pExp2 && pExp3 && pExp4 )
                return new CCreate_Line_command( pExp1, pExp2, pExp3, pExp4 );
            else
                 throw std::exception();
        }
    }
    else if ( sShape == "circle" )
    {
        if ( lstArgs.size() == 3 )
        {
            CExpr* pExp1 = parseExpresion( lstArgs[0] );
            CExpr* pExp2 = parseExpresion( lstArgs[1] );
            CExpr* pExp3 = parseExpresion( lstArgs[2] );

            if ( pExp1 && pExp2 && pExp3 )
                return new CCreate_Circle_Command( pExp1, pExp2, pExp3 );
            else
                 throw std::exception();
        }
    }

    throw std::exception();

    return NULL;
}


CExpr* CCommand_Parser::parseCommand( QStringList& sTokenList )
{
    QString sToken = sTokenList.first();
    sTokenList.pop_front();

    cmdService* pService = cmdService::getInstance();
    command *pCommand = pService->getCommand( sToken.toStdString() );

    return pCommand;
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
            sWord.clear();
        }
        ++it;
    }
    if (!sWord.isEmpty())
        lstWords.append(sWord);

    return lstWords;
}


bool CCommand_Parser::isAssigne( const QString& sToken ) const
{
    return (sToken == "=");
}


bool CCommand_Parser::isPlus( const QString& sToken ) const
{
    return ( sToken == "+" );
}


bool CCommand_Parser::isMinus( const QString& sToken ) const
{
    return ( sToken == "-" );
}


bool CCommand_Parser::isVarible( const QString& sToken ) const
{
    if ( sToken.isEmpty() || isPlus( sToken[0] ) || isMinus( sToken[0] )
        || isDigit( sToken[0] ) || isAssigne( sToken[0] ) )
    {
        return false;
    }

    return true;
}

bool CCommand_Parser::isDigit( const QString& sToken ) const
{
    bool bOK = false;
    sToken.toDouble( &bOK );

    return bOK;
}


bool CCommand_Parser::isCommand( const QString& sToken ) const
{
    return ( ( sToken == "exit" ) || ( sToken == "clear" ) );
}


bool CCommand_Parser::isShape( const QString& sToken ) const
{
    return ( ( sToken == "rect" ) || ( sToken == "squer" ) ||
             ( sToken == "line" ) || ( sToken == "circle" ) );
}




