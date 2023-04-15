#pragma once
#include <string>

struct Location {
	Location() = default;
	Location(std::string dot) : row(dot[0] - 'a'), col(dot[1] - '1') {}
	Location(const int r, const int c) : row(r), col(c) {}

	int row = 0;
	int col = 0;
};


enum class Path {NONE, HORIZONTAL, VERTICAL, DIAGONAL, STEPS};
