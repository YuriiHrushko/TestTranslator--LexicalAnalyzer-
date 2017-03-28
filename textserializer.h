#ifndef TEXTSERIALIZER_H
#define TEXTSERIALIZER_H

#include <QVector>

class TextSerializer
{
public:
    TextSerializer();
    QVector<QString> readFile(QString filepath);
    void writeFile(QString filepath, QString Lexem, QString Coordinates);
/*
signals:

public slots:
*/
};

#endif // TEXTSERIALIZER_H
