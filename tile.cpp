#include "tile.h"
#include <iostream>
using namespace std;

Tile::Tile(int x_, int y_, Piece *piece_) {
    x = x_;
    y = y_;
    piece = piece_;
}

void Tile::print() {
    // empty tile
    if (piece == nullptr) {
        cout << " ";
    }

    else {
        piece->print();
    }
}

int Tile::get_x() {
    return x;
}

int Tile::get_y() {
    return y;
}

Piece* Tile::get_piece() {
    return piece;
}
