#include "Knight.h"

// add the key and value of the piece to the factory
bool Knight::m_creator = PieceFactory::getFactory().addCreator(
    'n', [](const char& sign) { return std::make_unique<Knight>(sign); });


Knight::Knight(char sign)
    : Piece(sign)
{}



//       *   * 
//     *       *
//         N  
//     *       *
//       *   * 
//
bool Knight::move(const Location& src, const Location& dest) const
{
    //(2,1)(2,-1)(-2,1)(-2,-2)(1,2)(1,-2)(-1,2)(-1,-2)
    auto rowDiff = std::abs(src.row - dest.row);
    auto coldiff = std::abs(src.col - dest.col);

    return (rowDiff == 2 && coldiff == 1) || (rowDiff == 1 && coldiff == 2);
}

bool Knight::needToCheckPath() const
{
    return false;
}
