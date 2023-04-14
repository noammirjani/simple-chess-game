#pragma once
#include <string>

struct Location {

	Location(std::string dot) : row(dot[0] - 'a'), col(dot[1] - '1') {}
	Location(const int r, const int c) : row(r), col(c) {}

	int row;
	int col;

	Location operator-(const Location& other) {
		return { row - other.row, col - other.col };
	}

};


enum class Path {NONE, HORIZONTAL, VERTICAL, DIAGONAL, STEPS};
