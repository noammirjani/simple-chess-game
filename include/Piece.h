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

	// pure virtal function
	virtual bool move(const Location&, const Location&) const = 0;

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
