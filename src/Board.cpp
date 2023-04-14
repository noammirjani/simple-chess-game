#include "Board.h"

Board::Board() {

	std::string boardSTR = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
	setBoard(boardSTR);
	m_playerTurn = White; 
}


Board::Board(const std::string& boardSTR) {
	setBoard(boardSTR);
	m_playerTurn = White;
}


void Board::setBoard(const std::string& board){ 
	m_board.clear();


	for (auto row = 0, index = 0; row < 8; ++row) {
		PiecePtrArray temp;
		
		for (auto col = 0; col < 8; ++col, ++index) {
			temp.emplace_back(PieceFactory::getFactory().create(board[index]));
		}

		m_board.emplace_back(std::move(temp)); 
	}
}


int Board::codeResponseOfMove(const std::string& moveInput) {

	Location src(moveInput.substr(0, 2)), dest(moveInput.substr(2, 4));

	if (m_board[src.row][src.col] == nullptr)
		return (int)PossibleErrors::NO_PIECE_IN_SRC_LOCATION;

	if (m_board[src.row][src.col]->isMyTurn(m_playerTurn))
		return (int)PossibleErrors::PIECE_OF_OPPONENT;



	/*
	if (*m_board[src.row][src.col] == *m_board[dest.row][dest.col])
		return (int)PossibleErrors::SAME_COLOR_PIECES;

	if(!isValidMove(src, dest))
		return (int)PossibleErrors::ILLIGAL_MOVEMENT;

	

	//isCheckmate = isCheck(); 
	if (m_board[dest.row][dest.col] != nullptr)
		m_board[dest.row][dest.col] = nullptr; 
	m_playerTurn = !m_playerTurn;
	// return isCheckmate ? 41 : 42; 

	*/

	updateBoard(src, dest); 

	m_playerTurn = !m_playerTurn; 
	return 42; 
}


void Board::updateBoard(const Location& src, const Location& dest) {

	// moving all the attributes of src to dest and src becomes nullptr
	m_board[dest.row][dest.col] = std::move(m_board[src.row][src.col]); 
	
}

//bool Board::isValidMove(const Location& src, const Location& dest) const
//{
//	auto path = m_board[src.row][src.col]->move(src, dest);
//	
//	return isCleanPath(src, dest, path); 
//}
//
//
//bool Board::isCleanPath(const Location& src, const Location& dest, const Path& path) const
//{
//	switch (path)
//	{
//	case Path::HORIZONTAL: {
//		int start = std::min(src.row, dest.row);
//		int end = std::max(src.row, dest.row);
//		for (int row = start + 1; row < end; ++row)
//		{
//			if (m_board[row][src.col] != nullptr)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//
//	case Path::VERTICAL: {
//		int start = std::min(src.col, dest.col);
//		int end = std::max(src.col, dest.col);
//		for (int col = start + 1; col < end; ++col)
//		{
//			if (m_board[src.row][col] != nullptr)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//
//	case Path::DIAGONAL:
//		break;
//
//	case Path::STEPS:
//		return true;
//
//	case Path::NONE:
//	default:
//		return false; 
//	}
//
//	return false;
//}
//