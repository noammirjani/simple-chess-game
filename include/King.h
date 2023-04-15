#pragma once
#include "Piece.h"
#include "Location.h"
#include "PieceFactory.h"


class King : public Piece {
public:
    King(const char = 'k');
    bool move(const Location&, const Location&) const override;

private:
    static bool m_creator;

};
