#ifndef KNIGHT_H
#define KNIGHT_H

#include "../piece.h"

class Tile;
class Board;

class Knight : public Piece {
 public:
    virtual void move(Tile &from, Tile &destination, Board &board);
    Knight(Color color_);
    
 private:
    using Piece::move;

};

#endif
