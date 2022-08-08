#pragma once

#include <iostream>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "emptySquare.h"

enum class Fill
{
	EMPTY,
	CLASSIC,
	KNIGHT_FIGHT,
	PAWS_ONLY
};

Pos str_to_pos(std::string str);

 ref class Chessboard
{
	array<Piece^>^ m_array = gcnew array<Piece^>(65);


	EmptySquare^ m_emptySquare  = gcnew EmptySquare(NONE_POS, NONE_COLOR);

	bool isWayClear(Pos pos1, Pos pos2);
public:

	Chessboard(Fill fill);
	Color m_currentMoveColor = WHITE;
	//
	void add(Piece^ piece);
	void remove(Pos pos);
	void move(Pos pos1, Pos pos2);
	bool movePossible(Pos pos1, Pos pos2);


	Piece^ operator[] (const Pos index);
};

