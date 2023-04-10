#include "PieceFactory.h"


PieceFactory& PieceFactory::getFactoryInstance() {

	static PieceFactory factory;
	return factory;
}


std::unique_ptr<Piece> PieceFactory::create(const char sign)
{
	auto it = m_creator.find(std::toupper(sign));
	if (it == m_creator.end()) return nullptr;
	return it->second(sign);
}


void PieceFactory::addCreator(const char key, pieceCreator func) {

	m_creator.emplace(std::toupper(key), func);
}