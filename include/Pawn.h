#pragma once
#include "Piece.h"
#include "Location.h"
#include "PieceFactory.h"


class Pawn : public Piece {
public:
    Pawn(const char = 'p');
    bool move(const Location&, const Location&) const override;
    bool canMoveToCapture(const Location&, const Location&)const override;

private:
    static bool m_creator;

};
