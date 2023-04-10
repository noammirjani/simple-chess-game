#pragma once
#include <cctype>

enum class PlayerType { white, black };

class Piece {

public:
	Piece(const char);
	virtual ~Piece() = default;

	virtual int move() = 0;

private:
	PlayerType m_typeOfPlayer;

};



/*
	 // Register the product creation function with the factory
    static void Register() {
        Product::RegisterProduct("ConcreteProduct2", []() { return new ConcreteProduct2(); });
    }
*/
