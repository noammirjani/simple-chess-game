#pragma once
#include "Piece.h"
#include "Location.h"
#include "PieceFactory.h"
#include "Bishop.h"
#include "Rook.h"


class Queen : public Piece {
public:
    Queen(const char = 'q');
    bool move(const Location&, const Location&) const override;

private:
    static bool m_creator;
    Bishop m_verticalAndHorizontalMove;
    Rook m_diagonalMove;

};
