#include "chessboard.h"

//проверяет, есть ли преграды на пути
bool Chessboard::isWayClear(Pos pos1, Pos pos2)
{
	int row_now = (pos1 - 1) / 8;
	int row_go = (pos2 - 1) / 8;

	int column_now = pos1 - row_now * 8;
	int column_go = pos2 - row_go * 8;

	if (column_now == column_go)
	{
		if (abs(row_go - row_now) == 1) return true;
		if (row_go > row_now)
		{
			for (int i = row_now + 1; i < row_go; i++)
			{
				if (m_array[i * 8 + column_go] != m_emptySquare) return false;
			}
			return true;
		}
		if (row_go < row_now)
		{
			for (int i = row_go + 1; i < row_now; i++)
			{
				if (m_array[i * 8 + column_go] != m_emptySquare) return false;
			}
			return true;
		}
		return false;
	}

	if (row_now == row_go)
	{
		if (abs(column_go - column_now) == 1) return true;
		if (column_go > column_now)
		{
			for (int i = column_now + 1; i < column_go; i++)
			{
				if (m_array[row_now * 8 + i] != m_emptySquare) return false;
			}
			return true;
		}
		if (column_go < column_now)
		{
			for (int i = column_go + 1; i < column_now; i++)
			{
				if (m_array[row_now * 8 + i] != m_emptySquare) return false;
			}
			return true;
		}
		return false;
	}
	if ((abs(row_now - row_go) == 1) && (abs(column_now - column_go) == 1)) return true;
	if (column_now > column_go )
	{
		int temp_col = column_now - column_go - 1;
		if (row_now > row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now - i) * 8 + column_now - i] != m_emptySquare) return false;
			}
			return true;
		}
		if (row_now < row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now + i) * 8 + column_now - i] != m_emptySquare) return false;
			}
			return true;
		}
	}

	if (column_now < column_go)
	{
		int temp_col = column_go - column_now - 1;
		if (row_now > row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now - i) * 8 + column_now + i] != m_emptySquare) return false;
			}
			return true;
		}
		if (row_now < row_go)
		{
			for (int i = 1; i <= temp_col; i++)
			{
				if (m_array[(row_now + i) * 8 + column_now + i] != m_emptySquare) return false;
			}
			return true;
		}
	}
}

Chessboard::Chessboard(Fill fill)
{
	if (fill == Fill::EMPTY)
	{
		for (int i = 1; i < 65; i++)
		{
			m_array[i] = m_emptySquare;
		}
	}
	else if (fill == Fill::CLASSIC)
	{
		//white pieces

		m_array[a1] = gcnew Rook(a1, WHITE);
		m_array[b1] = gcnew Knight(b1, WHITE);
		m_array[c1] = gcnew Bishop(c1, WHITE);
		m_array[d1] = gcnew Queen(d1, WHITE);
		m_array[e1] = gcnew King(e1, WHITE);
		m_array[f1] = gcnew Bishop(f1, WHITE);
		m_array[g1] = gcnew Knight(g1, WHITE);
		m_array[h1] = gcnew Pawn(h1, WHITE);
		for (int i = a2; i < a3; i++)
			m_array[i] = gcnew Pawn((Pos)i, WHITE);

		//empty space of deck
		for (int i = a3; i < a7; i++)
			m_array[i] = m_emptySquare;

		//black pieces
		for (int i = a7; i < a8; i++)
			m_array[i] = gcnew Pawn((Pos)i, BLACK);

		m_array[a8] = gcnew Rook(a8, BLACK);
		m_array[b8] = gcnew Knight(b8, BLACK);
		m_array[c8] = gcnew Bishop(c8, BLACK);
		m_array[d8] = gcnew Queen(d8, BLACK);
		m_array[e8] = gcnew King(e8, BLACK);
		m_array[f8] = gcnew Bishop(f8, BLACK);
		m_array[g8] = gcnew Knight(g8, BLACK);
		m_array[h8] = gcnew Rook(h8, BLACK);
	}
	else if (fill == Fill::KNIGHT_FIGHT)
	{
		//white pieces
		for (int i = a1; i < a2; i++)
		{
			if (i == e1)
			{
				m_array[i] = gcnew King(e1, WHITE);
				continue;
			}
			m_array[i] = gcnew Knight((Pos)i, WHITE);
		}

		//empty space of deck
		for (int i = a2; i < a8; i++)
			m_array[i] = m_emptySquare;

		//black pieces
		for (int i = a8; i <= h8; i++)
		{
			if (i == e8)
			{
				m_array[i] = gcnew King(e8, BLACK);
				continue;
			}
			m_array[i] = gcnew Knight((Pos)i, BLACK);
		}
	}
	else if (fill == Fill::PAWS_ONLY)
	{
		//white pieces
		for (int i = a1; i < a3; i++)
		{
			if (i == e1)
			{
				m_array[i] = gcnew King(e1, WHITE);
				continue;
			}
			m_array[i] = gcnew Pawn((Pos)i, WHITE);
		}

		//empty space of deck
		for (int i = a3; i < a7; i++)
			m_array[i] = m_emptySquare;

		//black pieces
		for (int i = a7; i <= h8; i++)
		{
			if (i == e8)
			{
				m_array[i] = gcnew King(e8, BLACK);
				continue;
			}
			m_array[i] = gcnew Pawn((Pos)i, BLACK);
		}
	}
}

//добавление фигуры
void Chessboard::add(Piece^ piece)
{
	// если клетка не пустая, ошибка
	if (m_array[piece->getPos()] != m_emptySquare) abort();
	m_array[piece->getPos()] = piece;
}

//удаление фигуры
void Chessboard::remove(Pos pos)
{
	if (m_array[pos] == m_emptySquare) abort();
	delete m_array[pos];
	m_array[pos] = m_emptySquare;
}

void Chessboard::move(Pos pos1, Pos pos2)
{

	if (m_array[pos2] != m_emptySquare) this->remove(pos2);

	m_array[pos2] = m_array[pos1];
	m_array[pos1] = m_emptySquare;
	m_array[pos2]->setPos(pos2);

	if (m_currentMoveColor == WHITE)
		m_currentMoveColor = BLACK;
	else
		m_currentMoveColor = WHITE;
	return;

}

//проверка возможности хода
bool Chessboard::movePossible(Pos pos1, Pos pos2)
{
	//проверка цвета
	if (m_array[pos1]->getColor() != m_currentMoveColor) return 0;

	//т.к. у пешки сложный ход
	if (m_array[pos1]->getId() == PAWN)
	{
		if (*m_array[pos2] == *m_emptySquare)
		{
			int row_now = (pos1 - 1) / 8;
			int row_go = (pos2 - 1) / 8;
			int column_now = pos1 - row_now * 8;
			int column_go = pos2 - row_go * 8;
			bool canGo;
			if (m_array[pos1]->getColor() == WHITE)
			{
				canGo = (column_now == column_go) && (((row_now == 1) && (row_go - row_now <= 2) && (row_go - row_now > 0)) || (row_go - row_now == 1));

			}
			if (m_array[pos1]->getColor() == BLACK)
			{
				 canGo = (column_now == column_go) && (((row_now == 6) && (row_now - row_go <= 2) && (row_now - row_go > 0)) || (row_now - row_go == 1));

			}
			
			return canGo && isWayClear(pos1, pos2);
		}
	}
	return (m_array[pos1]->canGo(pos2)) && ((*m_array[pos2] == *m_emptySquare) || 
		((int)m_array[pos1]->getColor() + (int)m_array[pos2]->getColor() == 3)) && 
		(m_array[pos1]->getId() == KNIGHT ? 1 : this->isWayClear(pos1, pos2));
}

Piece^ Chessboard::operator[](const Pos index)
{
	return m_array[index];
}

Pos str_to_pos(std::string str)
{
	int column = 0;
	char alphabet[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	for (int i = 0; i < 8; i++)
		if (str[0] == alphabet[i]) column = i + 1;
	
	if (!column) abort();
	return (Pos)(column + ((int)(str[1] - '0') - 1) * 8);
}
