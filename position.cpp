#include "position.h"

Position::Position(int Pos, int Line){
    this->currentPos = Pos;
    this->currentLine = Line;
}

void Position::nextLine(){
    currentPos = 0;
    ++currentLine;
}

void Position::nextPos(){
    ++currentPos;
}

int Position::getLine(){
    return currentLine;
}

int Position::getPos(){
    return currentPos;
}

QString Position::toString(){
    return QString("%1 %2").arg(currentLine).arg(currentPos);
}
