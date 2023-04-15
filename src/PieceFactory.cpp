#include "PieceFactory.h"


//get function - only instance because of the singleton
PieceFactory& PieceFactory::getFactory() {

	static PieceFactory factory;
	return factory;
}


//get a sign(key to map that represents the piece) return pointer type std::unique_ptr<Piece>
std::unique_ptr<Piece> PieceFactory::create(const char& sign)
{
	auto it = m_creator.find(std::toupper(sign));
	//return (it == m_creator.end()) ? nullptr : it->second(sign);

	if (it != m_creator.end()) {
		return std::move(it->second(sign)); 
	}

	return nullptr;
}



// each piece has static member named creator -> 
//intilies in the cpp file and creates key+value that fits to map
bool PieceFactory::addCreator(const char& key, PieceCreator func) {

	m_creator.emplace(std::toupper(key), func);
	return true; 
}