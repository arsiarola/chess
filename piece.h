#ifndef PIECE_H
#define PIECE_H

class Piece;
class Board;
class Tile;

#include <string>
#include "macros.h"
#include "tools.h"

class Piece {
public:
    Piece(std::string = "", Color color = black);
    Piece(const Piece &piece);
    virtual bool move(Tile &from ,Tile &to, Board &board) = 0;
    
    std::string get_name() { return name; };
    Color get_color () { return color; };
    void print();
protected:
    std::string name;
    Color color;
};

#endif
