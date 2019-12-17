#ifndef PAWN_H
#define PAWN_H
#include "../piece.h"
#include "../tile.h"

#define UP -1
#define DOWN 1

class Pawn : public Piece {
    Pawn(std::string = "P", int color = 0);
    bool move(Tile, Tile);
};


#endif

