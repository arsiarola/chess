#ifndef PAWN_H
#define PAWN_H

#include "../piece.h"

class Tile;
class Board;

#define UP -1
#define DOWN 1

class Pawn : public Piece {
public:
    virtual bool move(Tile &from ,Tile &destination, Board &board);
    Pawn(int color_);
private:
    using Piece::move;

};


#endif

