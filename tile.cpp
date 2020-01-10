#include "board.h"
#include "piece.h"
#include "tile.h"
#include "tools.h"
#include <iostream>
#include <memory>

using std::cout;

Tile::Tile(int x_, int y_, Piece *piece_)
    : x(x_), y(y_), tile_num(x_ + (y_ * (BOARD_HEIGHT))), piece(piece_) {
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

// print one tile that is 3 characters wide and 1 high 
void Tile::print() const {
    // empty tile
    if (piece == nullptr) {
        cout << "   ";
    }

    // need to check for piece color since the padding will be
    // different color 
    else if (piece->get_color() == Color::black) {
	cout << P_BLC << " " << P_RST;
	piece->print();
	cout << P_BLC << " " << P_RST;
    }
	
    else if (piece->get_color() == Color::white) {
	cout << P_WHT << " ";
	piece->print();
	cout << P_WHT << " ";
    }
    print_separator();
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

// move piece leaving the argument tile pieceless
void Tile::assign_tile(Tile *from) {
    free_piece();
    piece = from->piece;
    from->piece = nullptr;
}

// Switch the owners of two pieces
void Tile::switch_tiles(Tile *tile) {
    Piece *temporary = tile->piece;
    tile->piece = piece;
    piece = temporary;
}

// call piece's move function if this tile contains a piece and
// if it's different tile where we are trying to move
void Tile::move(Tile &to, Board &board) {
    if (piece == nullptr) {
	throw "No piece found";
    }

    if (tile_num == to.tile_num) {
	throw "Move has to be a different piece from original tile";
    }
    
    piece->move(*this, to, board);
    // if pieces move doesn't throw an error we have to refresh the screen
    // since the piece was moved
    board.refresh_screen();
}

// free pieces data 
void Tile::free_piece() {
    if (piece != nullptr) {
        delete piece;
        piece = nullptr;
    }
}


std::string Tile::get_piece_name() {
    if (piece == nullptr) {
        return "";
    }

    return piece->get_name();
}
