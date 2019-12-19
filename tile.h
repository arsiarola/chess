#ifndef TILE_H
#define TILE_H

#include <memory>
#include "piece.h"

class Tile {
public:
    Tile(Tile &tile);
    Tile(int x_ = 0, int y_ = 0, std::unique_ptr<Piece> piece_ = nullptr);
    void print();
    int get_x();
    int get_y();
    bool has_piece();
    void remove_piece();
    void assign_piece(std::unique_ptr<Piece> piece_);
    void switch_pieces(std::unique_ptr<Piece> piece_);
private:
    int x;
    int y;
    std::unique_ptr<Piece> piece;
};
#endif
