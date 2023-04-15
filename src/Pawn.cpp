#include "Pawn.h"

// add the key and value of the piece to the factory
bool Pawn::m_creator = PieceFactory::getFactory().addCreator(
    'p', [](const char& sign) { return std::make_unique<Pawn>(sign); });


Pawn::Pawn(char sign)
    : Piece(sign)
{}


//  ~ ~ ~  
//          P  (1)
//        P *  
//        * *
// * *
// * p
// p          (6)
//  ~ ~ ~  
bool Pawn::move(const Location& src, const Location& dest) const
{
    auto rowDiff = dest.row - src.row;
    if (rowDiff != 0) return false;

    auto colDiff = std::abs(dest.col - src.col);
    auto startRowPawn = m_color ? 1 : 6;


    if (src.row == startRowPawn && colDiff <= 2)
        return true;


    return colDiff <= 1;
}