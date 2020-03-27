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
        for (int i = 0; i < TILE_WIDTH; ++i) {
            print_padding();
        }
        return;
    }

    for (int i = 0; i < TILE_HOR_PAD; ++i) {
        print_padding();
    }
    piece->print(tile_num);

    // The minus has to be here because if the block width is even number
    // it means we would otherwise print even_number / 2 + the piece which is too much
    for (int i = 0; i < TILE_HOR_PAD - (TILE_WIDTH % 2 == 0 ? 1 : 0) ; ++i) {
        print_padding();
    }

    // need to check for piece color since the padding will be
    // different color
    /* print_separator(); */
}

void Tile::print_padding() const {
    change_colors(tile_num_to_bg(tile_num));
    cout << " " << RESET;
}

int Tile::get_x() const {
    return x;
}

int Tile::get_y() const {
    return y;
}

bool Tile::has_piece() const {
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

const char* tile_num_to_bg(int tile_num) {
    int row = 0;
    while ((row+1) * 8 <= tile_num) {
        ++row;
    }

    /* cout << "Row = " << row << ", Tile_num = " << tile_num << "\n"; */

    if (row % 2 == 0) return tile_num % 2 == 0 ? BG_CYAN : BG_BLUE;
    else              return tile_num % 2 == 0 ? BG_BLUE : BG_CYAN;
}
