#include "piece.h"

bool Piece::operator==(Piece% piece)
{
	return (this->m_color == piece.getColor() && this->m_pos == piece.getPos() && this->m_id == piece.getId());
}

bool Piece::operator!=(Piece% piece)
{
	return !(*this == piece);
}
