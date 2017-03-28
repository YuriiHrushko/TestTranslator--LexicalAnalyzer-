#include "textserializer.h"

#include "QFile"
#include "QTextStream"
#include "QDebug"

TextSerializer::TextSerializer()
{

}

QVector<QString> TextSerializer::readFile(QString filepath){
    QVector<QString> Vect;
    QFile fileIn(filepath);
    if (!fileIn.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug();
    QTextStream in(&fileIn);
    while (!in.atEnd()){
        Vect.append(in.readLine());
    }
    return Vect;
}

void TextSerializer::writeFile(QString filepath, QString CodeLexem, QString Coordinates){
    QFile fileOut(filepath);
    if (fileOut.open(QIODevice::Append | QIODevice::Text)){
        QTextStream writeStream(&fileOut);
        if (Coordinates == "")
             writeStream <<  CodeLexem << "\n";
        else
            writeStream <<  CodeLexem << " " << Coordinates << "\n";
    }
}
