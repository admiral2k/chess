#pragma once
#include "piece.h"
ref class EmptySquare :
    public Piece
{
public:
    EmptySquare(Pos position, Color color) : Piece(position, color, NONE) {};

    bool canGo(Pos) override { return false; }
};

