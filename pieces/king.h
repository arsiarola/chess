#ifndef KING_H
#define KING_H

#include "../piece.h"
#include "../tools.h"

class Tile;
class Board;

class King : public Piece {
 public:
    virtual void move(Tile &from, Tile &destination, Board &board);
    King(Color color_);
    
 private:
    using Piece::move;

};

#endif
