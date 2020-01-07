#ifndef BISHOP_H
#define BISHOP_H

#include "../piece.h"

class Tile;
class Board;

class Bishop : public Piece {
 public:
    virtual void move(Tile &from, Tile &destination, Board &board);
    Bishop(Color color_);
    
 private:
    using Piece::move;

};

#endif
