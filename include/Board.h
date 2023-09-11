#pragma once
#include <vector>
#include <utility>
#include <string>
#include "PieceFactory.h"
#include "Piece.h"
#include "Location.h"
#include <sstream>
#include <algorithm>


enum class PossibleErrors {

	NO_PIECE_IN_SRC_LOCATION = 11,
	PIECE_OF_OPPONENT = 12,
	SAME_COLOR_PIECES = 13,
	ILLIGAL_MOVEMENT = 21,
	SELF_CHECK = 31,

};


enum class ValidMoveCodes {

	CHECK_TO_OPPONENT = 41,
	FINE_MOVE = 42,

};


enum PlayerColor { White = true, Black = false };


class Board {

public:
	using PiecePtr = PieceFactory::PiecePtr;
	using PiecePtrArray = std::vector<PiecePtr>;
	using ChessMatrix = std::vector<PiecePtrArray>;


	Board(const std::string&);
	~Board() = default; 
 
	int codeResponseOfMove(const std::string&);

private:
	ChessMatrix m_board;
	bool m_playerTurn; 
	const int m_SIZE = 8;

	//set board
	void setBoard(const std::string&);
	void updateBoard(const Location&, const Location&); 

	//path checking
	bool occupiedDest(const Location&) const;
	bool isValidMove(const Location&, const Location&) const;
	bool isCleanPath(const Location&, const Location&) const;
	bool horizontalPath(const Location&, const Location&) const;
	bool verticalPath(const Location&, const Location&) const;
	bool diagonalPath(const Location&, const Location&) const;

	//check functionallity
	bool isSelfCheck(const Location&, const Location&);
	bool isCheck(const Location&, const bool)const;
	bool isCheckMove() const;
	std::optional<Location> getKingLocation(const bool) const;
};