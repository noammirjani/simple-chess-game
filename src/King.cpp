#include "King.h"

// add the key and value of the piece to the factory
bool King::m_creator = PieceFactory::getFactory().addCreator(
    'k', [](const char& sign) { return std::make_unique<King>(sign); });


King::King(char sign)
    : Piece(sign)
{}


//   *  *  *
//   *  K  *
//   *  *  *
bool King::move(const Location& src, const Location& dest) const
{
    int row_diff = std::abs(dest.row - src.row);
    int col_diff = std::abs(dest.col - src.col);

    // src and dest are in the same location 
    if (row_diff == 0 && col_diff == 0) return false; 

    return (row_diff <= 1 && col_diff <= 1);
}
