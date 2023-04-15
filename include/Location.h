#pragma once

#include <string>
#include <cstdint>


/*
 * struct represents a 2D location on a chess board using 
 * the zero-indexed row and column numbers.
*/
struct Location {
    explicit Location(std::string dot) : row(dot[0] - 'a'), col(dot[1] - '1') {}
    Location(const uint8_t r, const uint8_t c) : row(r), col(c) {}

    int row = 0;
    int col = 0;
};
