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
    virtual bool move(Tile , Board &board);
    std::string get_name();
    void print();
protected:
    std::string name;
    int color;
};

#endif
