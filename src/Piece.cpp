#include "Piece.h"


Piece::Piece(const char pieceSign)
	:m_sign(pieceSign), m_color(std::isupper(pieceSign)){}


const char Piece::getSign() const {

	return m_sign;
}


bool Piece::isMyTurn(const bool realTurnColor) const {

	return m_color == realTurnColor; 
}

const bool Piece::getColor() const
{
	return m_color;
}


bool Piece::operator==(const Piece* other) const {

	return other && m_color == other->getColor();
}


void Piece::toString() const{
	std::cout << m_sign << " " << (m_color) ? "white" : "black";
}

//PlayerType::E_Color Piece::getColor(const char sign) const {
//	return std::isupper(sign) ? PlayerColor::black : PlayerColor::white;
//}
//
//bool Piece::operator==(const Piece* other) {
//	if (other == nullptr) return false; 
//
//	//return if the two pieces are from the same team
//	return (std::isupper(m_sign) && std::isupper(other->m_sign));
//}
// 
//
//bool Piece::isMyTurn(const PlayerType& realTurn)
//{
//	return realTurn == m_typeOfPlayer;
//}