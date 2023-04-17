#pragma once
#include <iostream>
#include "Location.h"


class Board; 
class PieceFactory; 

class Piece
{
public:
	Piece(const char);
	virtual ~Piece() = default;

	// pure virtal function - gets: src and dest location - checks the base and original moves 
	virtual bool move(const Location&, const Location&) const = 0;
	// virtual function - checks if the piece and capture in a special move
	virtual bool canMoveToCapture(const Location&, const Location&)const { return false;  }

	//informatical functions
	bool isMyTurn(const bool) const;
	const bool getColor() const; 
	void toString()	const; 
	const char getSign() const;

	//overloading operator
	bool operator==(const Piece*)const;

protected:
	const bool m_color;

private:
	const char m_sign; 

};
