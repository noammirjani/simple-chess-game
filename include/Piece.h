#pragma once
#include <iostream>
#include <cctype>
#include <list>
#include "Location.h"

class Board; 
class PieceFactory; 

class Piece
{
public:
	Piece(const char);
	virtual ~Piece() = default;

	virtual Path move(const Location&, const Location&) = 0;
	bool isMyTurn(const bool) const;
	void toString() {
		std::cout << m_sign << " " << m_color ? "white" : "black";
	}

protected:
	const char getSign() const;

private:
	const char m_sign; 
	const bool m_color; 

};


//class PlayerType
//{
//public:
//	enum class E_Color { 
//		white, black, None
//	};
//
//	PlayerType(E_Color color) : m_color(color) {}
//
//	void operator=(const E_Color& otherColor)
//	{
//		this->m_color = otherColor;
//	}
//
//	E_Color getColor() {
//		return m_color;
//	}
//
//	bool operator==(const PlayerType& otherPlayer)
//	{
//		return m_color == otherPlayer.m_color;
//	}
//
//	PlayerType& operator!() {
//		if (m_color == E_Color::white)
//		{
//			this->m_color = E_Color::black;
//		}
//		else {
//			this->m_color = E_Color::white;
//		}
//		return *this;
//	}
//
//
//private:
//	E_Color m_color = E_Color::None;
//
//};

