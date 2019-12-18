#include "tile.h"
#include <iostream>
using namespace std;

Tile::Tile(int x_, int y_, Piece *piece_) {
    x = x_;
    y = y_;
    piece = piece_;
}

void Tile::print() {
    if (piece != nullptr) {
        cout << piece->get_name();
    }
}

int Tile::get_x() {
    return x;
}

int Tile::get_y() {
    return y;
}
