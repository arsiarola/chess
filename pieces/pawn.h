#ifndef PAWN_H
#define PAWN_H
#include "../piece.h"

#define UP -1
#define DOWN 1

class Pawn : public Piece {
    void move();
};


#endif

