#include "tile.h"
#include <iostream>
#include <memory>

using std::cout;

Tile::Tile(Tile &tile) {
    x = tile.x;
    y = tile.y;
    auto temp_piece = std::make_unique<Piece>(*(tile.piece));
    assign_piece(temp_piece);
}

Tile::Tile(int x_, int y_, std::unique_ptr<Piece> piece_) :
    x(x_),
    y(y_),
    piece(std::move(piece_))
{}

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

void Tile::remove_piece() {
    piece.release();
}

void Tile::assign_piece(std::unique_ptr<Piece> &piece_) {
    piece = std::move(piece_);
}

// Switch the owners of two pieces
void Tile::switch_pieces(std::unique_ptr<Piece> &piece_) {
    auto temporary = std::move(piece_);
    piece_ = std::move(piece);
    piece = std::move(temporary);
}


