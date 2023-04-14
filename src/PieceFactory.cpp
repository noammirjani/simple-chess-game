#include "PieceFactory.h"


PieceFactory& PieceFactory::getFactory() {

	static PieceFactory factory;
	return factory;
}

std::unique_ptr<Piece> PieceFactory::create(const char& sign)
{
	auto it = m_creator.find(std::toupper(sign));
	//return (it == m_creator.end()) ? nullptr : it->second(sign);

	if (it != m_creator.end()) {
		return std::move(it->second(sign)); 
	}

	return nullptr;
}


bool PieceFactory::addCreator(const char& key, PieceCreator func) {

	m_creator.emplace(std::toupper(key), func);
	return true; 
}