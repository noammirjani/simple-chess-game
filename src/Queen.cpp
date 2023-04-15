#include "Queen.h"

// add the key and value of the piece to the factory
bool Queen::m_creator = PieceFactory::getFactory().addCreator(
    'q', [](const char& sign) { return std::make_unique<Queen>(sign); });


Queen::Queen(char sign)
    : Piece(sign), m_verticalAndHorizontalMove(), m_diagonalMove()
{}


//  *   *   *
//   *  *  *
//* * *  Q  * * *
//   *  *  *
//  *   *   *
bool Queen::move(const Location& src, const Location& dest) const
{
    return m_verticalAndHorizontalMove.move(src, dest) || m_diagonalMove.move(src, dest);
}
