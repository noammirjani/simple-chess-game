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

	for (auto row = 0, index = 0; row < SIZE; ++row) {
		PiecePtrArray temp;
		
		for (auto col = 0; col < SIZE; ++col, ++index) {
			temp.emplace_back(PieceFactory::getFactory().create(board[index]));
		}

		m_board.emplace_back(std::move(temp)); 
	}
}


int Board::codeResponseOfMove(const std::string& moveInput) {

	Location src(moveInput.substr(0, 2)), dest(moveInput.substr(2, 4));

	if (m_board[src.row][src.col] == nullptr)
		return (int)PossibleErrors::NO_PIECE_IN_SRC_LOCATION;
	
	if (!m_board[src.row][src.col]->isMyTurn(m_playerTurn))
		return (int)PossibleErrors::PIECE_OF_OPPONENT;

	if (*m_board[src.row][src.col] == m_board[dest.row][dest.col].get())
		return (int)PossibleErrors::SAME_COLOR_PIECES;

	if (!isValidMove(src, dest))
		return (int)PossibleErrors::ILLIGAL_MOVEMENT;
	
	if (isSelfCheck(src,dest))
		return (int)PossibleErrors::SELF_CHECK;


	updateBoard(src, dest); 
	bool check = isCheckMove(); 
	m_playerTurn = !m_playerTurn;
	
	return check ? (int)ValidMoveCodes::CHECK_TO_OPPONENT : (int)ValidMoveCodes::FINE_MOVE;
}


void Board::updateBoard(const Location& src, const Location& dest) {

	// moving all the attributes of src to dest and src becomes nullptr
	m_board[dest.row][dest.col] = std::move(m_board[src.row][src.col]); 
	
}


bool Board::isValidMove(const Location& src, const Location& dest) const
{
	return m_board[src.row][src.col]->move(src, dest) && isCleanPath(src, dest);
}


bool Board::isCleanPath(const Location& src, const Location& dest) const {

	return horizontalPath(src, dest) || verticalPath(src, dest) || diagonalPath(src, dest);
}


bool Board::horizontalPath(const Location& src, const Location& dest) const {

	//check if horizontal move 
	if (src.row != dest.row)return false; 

	//check if clear path 
	int start = std::min(src.col, dest.col);
	int end = std::max(src.col, dest.col); 
	
	for (int col = start + 1; col < end; ++col)
	{
		if (m_board[src.row][col] != nullptr)
		{
			return false;
		}
	}
	return true;
}


bool Board::verticalPath(const Location& src, const Location& dest) const {

	//check if vertical move 
	if (src.col != dest.col)return false;

	//check if clear path 
	int start = std::min(src.row, dest.row);
	int end	  = std::max(src.row, dest.row);

	for (int row = start + 1; row < end; row++)
	{
		if (m_board[row][src.col] != nullptr)
		{
			return false;
		}
	}

	return true;
}


bool Board::diagonalPath(const Location& src, const Location& dest) const {

	// check if diagonal move 
	int rowDiff = std::abs(dest.row - src.row);
	int colDiff = std::abs(dest.col - src.col);
	if (rowDiff != colDiff) return false;
	
	//check if clear path 
    int rowStart = std::min(src.row, dest.row);
	int rowEnd   = std::max(src.row, dest.row);
    int colStart = std::min(src.col, dest.col);
    int colEnd   = std::max(src.col, dest.col);

	for (int row = rowStart + 1, col = colStart + 1;
		 row < rowEnd && col < colEnd;
		 row++, col++)
	{
		if (m_board[row][col] != nullptr)
		{
			return false;
		}
	}

	return true; 
}


std::optional<Location> Board::getKingLocation(const bool team) const {

	const char WantedKing = team ? 'K' : 'k';

	for (auto row = 0; row < SIZE; ++row)
	{
		for (auto col = 0; col < SIZE; ++col)
		{
			if (m_board[row][col] != nullptr &&
				m_board[row][col]->getSign() == WantedKing &&
				m_board[row][col]->getColor() == team)
			{
				return Location(row, col);
			}
		}
	}

	return {};
}


bool Board::isSelfCheck(const Location& src, const Location& dest){

	auto kingLoc = getKingLocation(m_playerTurn);
	if (!kingLoc) return false; //doesnt exist

	updateBoard(src, dest);
	bool check = isCheck(*kingLoc, m_playerTurn); 
	updateBoard(dest, src);
	return check ; 
}


bool Board::isCheck(const Location& targetKing, const bool currTeam)const {

	for (auto row = 0; row < SIZE; ++row)
	{
		for (auto col = 0; col < m_board[row].size(); ++col)
		{
			if (m_board[row][col] != nullptr &&
				m_board[row][col]->getColor() != currTeam &&
				isValidMove(Location(row, col), targetKing))
			{
				return true;
			}		
		}
	}

	return false; 
}


bool Board::isCheckMove() const {

	auto kingLoc = getKingLocation(!m_playerTurn);
	return kingLoc && isCheck(*kingLoc, !m_playerTurn);
}