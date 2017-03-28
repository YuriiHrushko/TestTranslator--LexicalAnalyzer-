#include "parser.h"

#include <QDebug>

Parser::Parser()
{

}

void Parser::parse(QString filepathprogram, QString filepathdelimeters, QString filepathkeywords,
                   QString filepathout, QString fileuseridentifiers, QString fileuserconstants){

    int num1 = 0, num2 = 0;
    bool isMinus = false;

    QVector<QString> Delimeter = RWFile.readFile(filepathdelimeters);
    QVector<QString> KeyWord = RWFile.readFile(filepathkeywords);

    QFile fileIn(filepathprogram);
    if (!fileIn.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Ошибка при открытии файла";
    QTextStream in(&fileIn);
    in >> currentChar;
    while (!in.atEnd()){
// isIdentifier
        if (currentChar.isLetter()){
            do{
                Buffer += currentChar;
                currentSymbol.nextPos();
                in >> currentChar;
            } while (currentChar.isLetterOrNumber());
            if (KeyWord.contains(Buffer)){
                Buffer = QString::number(KeyWord.indexOf(Buffer) + keyWordsOffset);
                RWFile.writeFile(filepathout, Buffer, currentSymbol.toString());
                Buffer = "";
            } else {
                if (userIdentifiers.contains(Buffer)){
                    Buffer = QString::number(userIdentifiers.indexOf(Buffer) + identifierOffset);
                    RWFile.writeFile(filepathout, Buffer, currentSymbol.toString());
                    Buffer = "";
                } else {
                    userIdentifiers.append(Buffer);
                    RWFile.writeFile(fileuseridentifiers, Buffer, QString::number(userIdentifiers.indexOf(Buffer) + identifierOffset));
                    Buffer = QString::number(userIdentifiers.indexOf(Buffer) + identifierOffset);
                    RWFile.writeFile(filepathout, Buffer, currentSymbol.toString());
                    Buffer = "";
                }
            }
        }
// isDelimeter
        if (Delimeter.contains(currentChar)){
            Buffer += currentChar;
            currentSymbol.nextPos();
            Buffer = QString::number(Delimeter.indexOf(Buffer));
            RWFile.writeFile(filepathout, Buffer, currentSymbol.toString());
            Buffer = "";
            in >> currentChar;
        }
// isNumber
        if (currentChar.isNumber()){
            num1 = parseNumber(in);
            Buffer = "";
            if (currentChar == '#'){
                in >> currentChar;
                currentSymbol.nextPos();
                if (currentChar == '-'){
                    isMinus = true;
                    in >> currentChar;
                    currentSymbol.nextPos();
                }
                else if (currentChar == '+')
                    in >> currentChar;
                    currentSymbol.nextPos();
                if (currentChar.isNumber()){
                    num2 = parseNumber(in);
                    Buffer = "";
                }
                if (isMinus)
                    num1 = (-num1)/num2;
                else
                    num1 = num1/num2;
            }
            Buffer = QString::number(num1);

            if (userConstans.contains(Buffer)){
                Buffer = QString::number(userConstans.indexOf(Buffer) + constantsOffset);
                RWFile.writeFile(filepathout, Buffer, currentSymbol.toString());
                Buffer = "";
            } else {
                userConstans.append(Buffer);
                RWFile.writeFile(fileuserconstants, Buffer, "");
                Buffer = QString::number(userConstans.indexOf(Buffer) + constantsOffset);
                RWFile.writeFile(filepathout, Buffer, currentSymbol.toString());
                Buffer = "";
            }
        }
// isWhiteSpace
        if (currentChar == '\n' || currentChar == '\t' || currentChar == ' '){
            if (currentChar == '\n'){
                currentSymbol.nextLine();
                in >> currentChar;
            } else {
                currentSymbol.nextPos();
                in >> currentChar;
            }
        }
// isComment
        if (currentChar == '('){
            QChar ch;
            in >> currentChar;
            if (currentChar == '*'){
                while (!(ch == '*' && currentChar == ')')){
                    ch = currentChar;
                    in >> currentChar;
                    if (in.atEnd())
                        qDebug() << "Error! End of file.";
                }
                in >> currentChar;
            }
        }

    }
fileIn.close();
}

int Parser::parseNumber(QTextStream &in){
    do{
        Buffer += currentChar;
        currentSymbol.nextPos();
        in >> currentChar;
    } while (currentChar.isNumber());
    return Buffer.toInt();
}
