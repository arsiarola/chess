#ifndef PIECE_H
#define PIECE_H

class Piece;
class Board;
class Tile;

#include <string>
#include "macros.h"

class Piece {
public:
    Piece(std::string = "", int color = 0);
    Piece(const Piece &piece);
    virtual bool move(Tile &from ,Tile &to, Board &board) = 0;
    std::string get_name();
    void print();
protected:
    std::string name;
    int color;
};

#endif
