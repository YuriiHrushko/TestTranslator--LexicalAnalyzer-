#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QTextStream>
#include <QFile>

#include <textserializer.h>
#include <position.h>

class Parser
{
public:
    Parser();
    void parse(QString filepathprogram, QString filepathdelimeters, QString filepathkeywords, QString filepathout, QString fileuseridentifiers, QString fileuserconstants);

    Position currentSymbol = Position(0, 0);
    TextSerializer RWFile = TextSerializer();

private:
    QChar currentChar;
    QString Buffer;

    int parseNumber(QTextStream &in);
    QVector<QString> userIdentifiers;
    QVector<QString> userConstans;


    int keyWordsOffset = 401;
    int constantsOffset = 501;
    int identifierOffset = 1001;
/*
signals:

public slots:
*/
};

#endif // PARSER_H
