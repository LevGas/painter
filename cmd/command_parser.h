#ifndef CCOMMAND_PARSER_H
#define CCOMMAND_PARSER_H

#include <QString>
#include <QStringList>

typedef class CCommand_Parser
{
public:
    ~CCommand_Parser();

    void parse(const QString & sCommand);

    static CCommand_Parser* getInstance();
    static void deleteInstance();

private:
    CCommand_Parser();
    CCommand_Parser(const CCommand_Parser&);
    CCommand_Parser& operator=(const CCommand_Parser&);

    QStringList splitCommand(const QString & sCommand);

private:
    static CCommand_Parser* m_pInstance;

} parser;

#endif // CCOMMAND_PARSER_H
