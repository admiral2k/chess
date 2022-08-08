#pragma once
#include "piece.h"
ref class King :
    public Piece
{
public:
    King(Pos position, Color color) : Piece(position, color, KING) {};

    bool canGo(Pos pos) override;
};

