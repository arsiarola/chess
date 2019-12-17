#ifndef EMPTY_H
#define EMPTY_H

#include <string>
#include "../piece.h"

class Empty : public Piece {
    Empty(std::string = " ", int x = 0, int y = 0, int color = 0);
    bool move();
};

#endif
