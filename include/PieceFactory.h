#pragma once
#include <unordered_map>
#include <utility>
#include <memory>
#include <cctype>
#include <functional>
#include "Piece.h"

class PieceFactory {
public:
    using PiecePtr = std::unique_ptr<Piece>;
    using PieceCreator = std::function<PiecePtr(const char&)>;

    static PieceFactory& getFactory();
    PiecePtr create(const char& sign);
    bool addCreator(const char& key, PieceCreator func);

private:
    std::unordered_map<char, PieceCreator> m_creator;

    PieceFactory() = default;
    PieceFactory(const PieceFactory&) = delete;
    PieceFactory& operator=(const PieceFactory&) = delete;
};
