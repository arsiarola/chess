#ifndef TILE_H
#define TILE_H

#include <memory>
#include "piece.h"

class Tile {
public:
    Tile();
    Tile(int x, int y, Piece piece);
    void print();
    int get_x();
    int get_y();
private:
    int x;
    int y;
    Piece piece;
};
#endif
