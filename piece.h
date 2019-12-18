#ifndef PIECE_H
#define PIECE_H

class Piece;
class Board;

#include <string>
#include "macros.h"

class Piece {
public:
    Piece(std::string = "", int color = 0);
    virtual bool move(int from_x, int from_y, int to_x, int to_y, Board &board);
    std::string get_name();
    void print();
protected:
    std::string name;
    int color;
};

#endif
