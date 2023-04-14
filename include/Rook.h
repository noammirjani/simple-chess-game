#pragma once
#include "Piece.h"
#include "Location.h"


class Rook : public Piece {
public:
    Rook(char);
    Path move(const Location&, const Location&) override;

private:
    static bool m_creator;


};