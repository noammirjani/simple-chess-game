#include "Piece.h"


Piece::Piece(const char pieceSign)
	:m_sign(pieceSign), m_color(std::isupper(pieceSign)) {}


// returns the true original of the piece 
const char Piece::getSign() const {

	return m_sign;
}


// gets boolean that represents the current turn, checks if the 
// piece are in the same team 
bool Piece::isMyTurn(const bool realTurnColor) const {

	return m_color == realTurnColor;
}

//reurn boolean that represents the team of the piece
const bool Piece::getColor() const
{
	return m_color;
}


//overloading perator ==, checks if the pieces are from the same team
// does not check if the are the same exact piece!
bool Piece::operator==(const Piece* other) const {

	return other && m_color == other->getColor();
}


// print the data of te piece 
void Piece::toString() const {
	std::cout << m_sign << " " << (m_color) ? "white" : "black";
}
