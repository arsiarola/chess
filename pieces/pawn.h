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
    Pawn(Color color_);
private:
    bool move_black(Tile &from, Tile &destination);
    bool move_white(Tile &from, Tile &destination);
    using Piece::move;
    bool first_move = true;
};


#endif

