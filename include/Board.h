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

};


enum PlayerColor { White = false, Black = true };


class Board {

public:
	using PiecePtr = PieceFactory::PiecePtr;
	using PiecePtrArray = std::vector<PiecePtr>;
	using ChessMatrix = std::vector<PiecePtrArray>;


	Board();
	Board(const std::string&);
	~Board() = default; 
 
	int codeResponseOfMove(const std::string&);

private:
	ChessMatrix m_board;
	bool m_playerTurn; 
	
	void setBoard(const std::string&);
	void updateBoard(const Location&, const Location&); 
	bool isValidMove(const Location&, const Location&) const; 
	bool isCleanPath(const Location&, const Location&, const Path&) const;
};