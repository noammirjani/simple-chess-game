#include "Rook.h"
#include "PieceFactory.h"

bool Rook::m_creator = PieceFactory::getFactory().addCreator(
    'r', [](const char& sign) { return std::make_unique<Rook>(sign); });


Rook::Rook(char sign)
    : Piece(sign)
{}


bool Rook::move(const Location& src, const Location& dest) const
{
    auto dirX = std::abs(src.col - dest.col), dirY = std::abs(src.row - dest.row); 
    
    return (dirX && !dirY) || (!dirX && dirY);
}