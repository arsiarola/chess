#include "piece.h"
#include "tile.h"
#include <iostream>
#include <memory>

using std::cout;

Tile::Tile(int x_, int y_, Piece * piece_) :
    x(x_),
    y(y_),
    piece(piece_)
{}

Tile& Tile::operator= (const Tile &tile) {
    x = tile.x;
    y = tile.y;
    piece = tile.piece;
    return *this;
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

bool Tile::has_piece() {
    return piece != nullptr;
}


void Tile::assign_piece(Piece *piece_) {
    piece = std::move(piece_);
}

// Switch the owners of two pieces
void Tile::switch_pieces(Piece *piece_) {
    auto temporary = std::move(piece_);
    piece_ = std::move(piece);
    piece = std::move(temporary);
}


