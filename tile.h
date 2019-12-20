#ifndef TILE_H
#define TILE_H

#include "piece.h"
class Board;

class Tile {
public:
    Tile(int x_ = 0, int y_ = 0, Piece *piece = nullptr);
    Tile& operator=(const Tile &tile);
    void print();
    int get_x();
    int get_y();
    bool has_piece();
    void remove_piece();
    void assign_piece(Piece *piece_);
    void switch_pieces(Piece *piece_);
    void move(Tile &from, Tile &to, Board &board);
private:
    int x;
    int y;
    Piece *piece;
};
#endif
