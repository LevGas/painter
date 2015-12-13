#ifndef CCOMMAND_PARSER_H
#define CCOMMAND_PARSER_H

#include <QString>
#include <QStringList>
#include "commands/expresion.h"


typedef class CCommand_Parser
{
public:
    ~CCommand_Parser();

private:
    CCommand_Parser();
    CCommand_Parser(const CCommand_Parser&);
    CCommand_Parser& operator=(const CCommand_Parser&);

public:
    static CCommand_Parser* getInstance();
    static void deleteInstance();

public:
    void parse(const QString & sLine);


private:
    QStringList splitCommand(const QString & sCommand);

    CExpr* parseExpresion( QStringList& sTokenList );
    CExpr* parseShape( QStringList& sTokenList );
    CExpr* parseCommand( QStringList& sTokenList );

    bool isAssigne( const QString& sToken ) const;
    bool isPlus( const QString& sToken ) const;
    bool isMinus( const QString& sToken ) const;
    bool isVarible( const QString& sToken ) const;
    bool isDigit( const QString& sToken ) const;
    bool isCommand( const QString& sToken ) const;
    bool isShape( const QString& sToken ) const;

private:
    static CCommand_Parser* m_pInstance;

private:
    CContext m_context;

} parser;

#endif // CCOMMAND_PARSER_H
