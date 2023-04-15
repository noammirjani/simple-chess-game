#include "Bishop.h"

// add the key and value of the piece to the factory
bool Bishop::m_creator = PieceFactory::getFactory().addCreator(
    'b', [](const char& sign) { return std::make_unique<Bishop>(sign); });


Bishop::Bishop(char sign)
    : Piece(sign)
{}


//*     *
// *   *
//  * *
//   B
//  * *
// *   *
//*     *
bool Bishop::move(const Location& src, const Location& dest) const
{
    auto rowDiff = std::abs(src.row - dest.row); 
    auto colDiff  = std::abs(src.col - dest.col); 

    return rowDiff == colDiff;
}
