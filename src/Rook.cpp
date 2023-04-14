#include "Rook.h"
#include "PieceFactory.h"

bool Rook::m_creator = PieceFactory::getFactory().addCreator(
    'r', [](const char& sign) { return std::make_unique<Rook>(sign); });


Rook::Rook(char sign)
    : Piece(sign)
{}


Path Rook::move(const Location& src, const Location& dest)
{
    std::vector<Location> path; 

    auto dirX = std::abs(src.col - dest.col), dirY = std::abs(src.row - dest.row); 

    if ((dirX && !dirY) || (!dirX && dirY)) {

        return (src.row != dest.row) ? Path::HORIZONTAL : Path::VERTICAL;
    }
    
    return Path::NONE; 
}