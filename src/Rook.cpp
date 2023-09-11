#include "Rook.h"

// add the key and value of the piece to the factory
bool Rook::m_creator = PieceFactory::getFactory().addCreator(
    'r', [](const char& sign) { return std::make_unique<Rook>(sign); });


Rook::Rook(char sign)
    : Piece(sign)
{}

//      *
//      *
//      *
// * * * R * * * 
//      *
//      *
//      *
bool Rook::move(const Location& src, const Location& dest) const
{
    uint8_t dirX = std::abs(src.col - dest.col), dirY = std::abs(src.row - dest.row);  
    
    return (dirX == 0 && dirY > 0) || (dirX > 0 && dirY == 0);
}