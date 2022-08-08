#pragma once
#include "piece.h"
ref class Bishop :
    public Piece
{
public:
    Bishop(Pos position, Color color) : Piece(position, color, BISHOP) {};

    bool canGo(Pos pos) override;
};

