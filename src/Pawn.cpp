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
    //can only walk strait
    auto colDiff = dest.col - src.col;
    if (colDiff != 0) return false;


    auto rowDiff = dest.row - src.row;
    auto startRowPawn = m_color ? 1 : 6;

    // moving one step forward
    if ((m_color && rowDiff == 1) || (!m_color && rowDiff == -1))
        return true;

    // starting position - can move 2 steps forward 
    if (src.row == startRowPawn) {
        if ((m_color && rowDiff == 2) || (!m_color && rowDiff == -2))
            return true;
    }


    return false;
}