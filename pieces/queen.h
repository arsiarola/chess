#ifndef QUEEN_H
#define QUEEN_H

#include "../piece.h"
#include "../tools.h"

class Tile;
class Board;

class Queen : public Piece {
 public:
    virtual void move(Tile &from, Tile &destination, Board &board);
    Queen(Color color_);
    
 private:
    using Piece::move;

};

#endif
