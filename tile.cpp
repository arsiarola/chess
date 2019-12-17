#include "tile.h"
#include "pieces/empty.h"
#include <iostream>
using namespace std;

Tile::Tile(int x_, int y_, Piece piece_) {
    x = x;
    y = y;
    piece = piece_;
}

Tile::Tile() {
    x = 0;
    y = 0;
    Empty temp();
    piece = temp;
}

void Tile::print() {
    cout << piece.get_name();
}

int Tile::get_x() {
    return x;
}

int Tile::get_y() {
    return y;
}
