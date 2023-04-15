#pragma once
#include "Piece.h"
#include "Location.h"
#include "PieceFactory.h"


class King : public Piece {
public:
    King(char);
    bool move(const Location&, const Location&) const override;

private:
    static bool m_creator;

    //(0,1)         (0,-1)
    //(1,0)   (1,1) (1,-1)
    //(-1,0) (-1,1) (-1,-1)

};
