#pragma once
#include "piece.h"
ref class Rook :
    public Piece
{
public:
    Rook(Pos position, Color color) : Piece(position, color, ROOK) {};

    bool canGo(Pos pos) override;
};

