#include "board.h"
#include "piece.h"
#include "tile.h"
#include <iostream>
#include <memory>

using std::cout;

Tile::Tile(int x_, int y_, Piece *piece_)
    : x(x_), y(y_), tile_num(x_ + (y_ * (BOARD_HEIGHT))), piece(piece_) {
    cout << "tile_num = " << tile_num << "\n";
}

Tile& Tile::operator= (const Tile &tile) {
    x = tile.x;
    y = tile.y;
    tile_num = tile.tile_num;
    piece = tile.piece;
    return *this;
}

Color Tile::get_piece_color() {
    return piece->get_color();
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


void Tile::assign_tile(Tile *tile) {
    free_piece();
    piece = tile->piece;
    tile->piece = nullptr;
}

// Switch the owners of two pieces
void Tile::switch_tiles(Tile *tile) {
    Piece *temporary = tile->piece;
    tile->piece = piece;
    piece = temporary;
}


bool Tile::move(Tile &to, Board &board) {
    if (piece == nullptr) {
	return false;
    }
    return piece->move(*this, to, board);
}

void Tile::free_piece() {
    if (piece != nullptr) {
        delete piece;
        piece = nullptr;
    }
}
