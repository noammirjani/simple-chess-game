#pragma once
#include <unordered_map>
#include <utility>
#include <memory>
#include <cctype>
#include "Piece.h"



class PieceFactory {

public:
	using pieceCreator = std::unique_ptr<Piece>(*)(const char);

	static PieceFactory& getFactoryInstance();
	std::unique_ptr<Piece> create(const char sign);
	void addCreator(const char key, pieceCreator func);

private:
	std::unordered_map<char, pieceCreator> m_creator; 
	
	//ctor copt-ctor and operator=a
	PieceFactory() = default; 
	PieceFactory(const PieceFactory&) = delete;
	PieceFactory& operator=(const PieceFactory&) = delete;
};