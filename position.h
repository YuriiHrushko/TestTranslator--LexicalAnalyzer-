#ifndef POSITION_H
#define POSITION_H

#include <QString>

class Position
{
public:
    Position (int Pos, int Line);
    void nextLine();
    void nextPos();
    int getLine();
    int getPos();
    QString toString();


    int currentLine = 0;
    int currentPos = 0;
/*
signals:

public slots:
*/
};

#endif // POSITION_H
