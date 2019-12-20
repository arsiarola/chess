#ifndef PAWN_H
#define PAWN_H
#include "../piece.h"
#include "../tile.h"

#define UP -1
#define DOWN 1

class Pawn : public Piece {
public:
    virtual bool move(int from_x, int from_y, int to_x, int to_y, Board &board);
    Pawn(int color_ = 0);
private:

};


#endif

