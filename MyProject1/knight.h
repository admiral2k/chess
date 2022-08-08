#pragma once
#include "piece.h"
ref class Knight :
    public Piece
{
public:
    Knight(Pos position, Color color) : Piece(position, color, KNIGHT) {};

    bool canGo(Pos pos) override;
};

