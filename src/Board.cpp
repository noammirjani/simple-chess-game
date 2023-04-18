#include "Board.h"

//c-tor
Board::Board(const std::string& boardSTR) {
	setBoard(boardSTR);
	m_playerTurn = White;
}


//sets the board according to a given string representation of the board.
void Board::setBoard(const std::string& board) {

	m_board.clear();

	for (auto row = 0, index = 0; row < m_SIZE; ++row) {
		PiecePtrArray temp;

		for (auto col = 0; col < m_SIZE; ++col, ++index) {
			temp.emplace_back(PieceFactory::getFactory().create(board[index]));
		}

		m_board.emplace_back(std::move(temp));
	}
}


// function that takes in a move string and returns an int representing the result of the move
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

	if (isSelfCheck(src, dest))
		return (int)PossibleErrors::SELF_CHECK;


	updateBoard(src, dest);
	bool check = isCheckMove();
	m_playerTurn = !m_playerTurn;// switch to the other player's turn

	return check ? (int)ValidMoveCodes::CHECK_TO_OPPONENT : (int)ValidMoveCodes::FINE_MOVE;
}


// function that checks if a move is valid
void Board::updateBoard(const Location& src, const Location& dest) {

	// moving all the attributes of src to dest and src becomes nullptr
	m_board[dest.row][dest.col] = std::move(m_board[src.row][src.col]);

}


// helper function that checks if the path between two locations is clear
bool Board::isValidMove(const Location& src, const Location& dest) const
{
	auto move = m_board[src.row][src.col]->move(src, dest); 
	auto capture = occupiedDest(dest) && m_board[src.row][src.col]->canMoveToCapture(src, dest);
	return (move || capture) && isCleanPath(src, dest); 

}


//Helper function - checks if the destination is occupied by a piece belonging to the other team
bool Board::occupiedDest(const Location& dest)const{
	return m_board[dest.row][dest.col] != nullptr &&
		   m_board[dest.row][dest.col]->isMyTurn(!m_playerTurn);
}


// check if the movement is valid based on the current state of the board 
bool Board::isCleanPath(const Location& src, const Location& dest) const {
	// there are pieces that doesnt need to check path in there movment like knight
	if (!m_board[src.row][src.col]->needToCheckPath()) return true;
	return horizontalPath(src, dest) || verticalPath(src, dest) || diagonalPath(src, dest);
}


// helper function that checks if a horizontal path is clear
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


// helper function that checks if a vertical path is clear
bool Board::verticalPath(const Location& src, const Location& dest) const {

	//check if vertical move 
	if (src.col != dest.col)return false;

	//check if clear path 
	int start = std::min(src.row, dest.row);
	int end = std::max(src.row, dest.row);

	for (int row = start + 1; row < end; row++)
	{
		if (m_board[row][src.col] != nullptr)
		{
			return false;
		}
	}

	return true;
}


// helper function that checks if a diagonal path is clear
bool Board::diagonalPath(const Location& src, const Location& dest) const {

	// check if diagonal move 
	int rowDiff = std::abs(dest.row - src.row);
	int colDiff = std::abs(dest.col - src.col);
	if (rowDiff != colDiff) return false;
	if (rowDiff == 1) return true; //one step dagonal - no need to check 

	//check if clear path 
	int rowStart = std::min(src.row, dest.row);
	int rowEnd = std::max(src.row, dest.row);
	int colStart = std::min(src.col, dest.col);
	int colEnd = std::max(src.col, dest.col);

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

// helper function that gets the location of the king for a given team
// return optional location -> if doesnt found the king(in case of winning/error) return nullopt
std::optional<Location> Board::getKingLocation(const bool team) const {

	const char WantedKing = team ? 'K' : 'k';

	for (auto row = 0; row < m_SIZE; ++row)
	{
		for (auto col = 0; col < m_SIZE; ++col)
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


// function that checks if a given move puts the player in check
bool Board::isSelfCheck(const Location& src, const Location& dest) {

	auto kingLoc = getKingLocation(m_playerTurn);
	if (!kingLoc) return false; //doesnt exist

	updateBoard(src, dest);
	bool check = isCheck(*kingLoc, m_playerTurn);
	updateBoard(dest, src);
	return check;
}


//checks whether a given player (currTeam) is in check by checking if any of the opponent's
//pieces can attack the king at the given targetKing location.
bool Board::isCheck(const Location& targetKing, const bool currTeam)const {

	for (auto row = 0; row < m_SIZE; ++row)
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


// checks whether the current player is in check after the last move.
bool Board::isCheckMove() const {

	auto kingLoc = getKingLocation(!m_playerTurn);
	return kingLoc && isCheck(*kingLoc, !m_playerTurn);
}