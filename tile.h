#ifndef TILE_H
#define TILE_H

#include <memory>
#include "piece.h"

class Tile {
public:
    Tile(int x = 0, int y = 0, Piece *piece = nullptr);
    void print();
    int get_x();
    int get_y();
    Piece* get_piece();
private:
    int x;
    int y;
    Piece *piece;
};
#endif
