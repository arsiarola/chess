#ifndef TILE_H
#define TILE_H

#include "tools.h"

class Board;
class Piece;

class Tile {
public:
    Tile(int x_ = 0, int y_ = 0, Piece *piece = nullptr);
    Tile& operator=(const Tile &tile);
    void print() const;
    int get_x() const;
    int get_y() const;
    bool has_piece() const;
    void free_piece();
    Color get_piece_color();
    
    
    void assign_tile(Tile *tile);
    void switch_tiles(Tile *tile);
    bool move(Tile &to, Board &board);
private:
    int x;
    int y;
    int tile_num;
    Piece *piece;
};
#endif
