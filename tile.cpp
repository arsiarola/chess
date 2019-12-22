#include "board.h"
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

void Tile::print() const{
    // empty tile
    if (piece == nullptr) {
        cout << " ";
    }

    else {
        piece->print();
    }
}

int Tile::get_x() const{
    return x;
}

int Tile::get_y() const{
    return y;
}

bool Tile::has_piece() const{
    return piece != nullptr;
}


void Tile::assign_piece(Piece *piece_) {
    remove_piece();
    piece = piece_;

    piece_->remove_piece();
    piece = nullptr;
}

// Switch the owners of two pieces
void Tile::switch_pieces(Piece *piece_) {
    auto temporary = std::move(piece_);
    piece_ = std::move(piece);
    piece = std::move(temporary);
}


void Tile::move(Tile &to, Board &board) {
    if (piece == nullptr) {
        return;
    }
    piece->move(*this, to, board);
}

void Tile::remove_piece() {
    if (piece != nullptr) {
        delete []piece;
    }
}
