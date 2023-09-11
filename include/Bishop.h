#pragma once
#include "Piece.h"
#include "Location.h"
#include "PieceFactory.h"


class Bishop : public Piece {
public:
    Bishop(const char = 'b');
    bool move(const Location&, const Location&) const override;

private:
    static bool m_creator;

};
