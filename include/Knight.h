#pragma once
#include "Piece.h"
#include "Location.h"
#include "PieceFactory.h"


class Knight : public Piece {
public:
    Knight(const char = 'n');
    bool move(const Location&, const Location&) const override;
    bool needToCheckPath()const override; 
private:
    static bool m_creator;

};