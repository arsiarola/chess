#ifndef ROOK_H
#define ROOK_H

#include "../piece.h"

class Tile;
class Board;

class Rook : public Piece {
public:  
    virtual void move(Tile &from, Tile &destination, Board &board);
    Rook(Color color_);

private:
    using Piece::move;
};

#endif
