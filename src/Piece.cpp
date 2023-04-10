#include "Piece.h"


Piece::Piece(const char pieceSign) {

	m_typeOfPlayer = std::isupper(pieceSign) ? PlayerType::black : PlayerType::white;
}

