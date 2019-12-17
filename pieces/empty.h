#ifndef EMPTY_H
#define EMPTY_H

#include <string>
#include "../piece.h"

class Empty : public Piece {
    Empty(std::string name_= " ",  int color_ = 0);
    bool move();
};

#endif
