#pragma once
#include "piece.h"
ref class Queen :
    public Piece
{
public:
    Queen(Pos position, Color color) : Piece(position, color, QUEEN) {};

    bool canGo(Pos pos) override;
};

