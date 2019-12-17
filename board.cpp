#include <memory>
#include <iostream>

#include "piece.h"
#include "board.h"
#include "tile.h"

using namespace std;

void Board::init_board() {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            Piece *piece = new Piece("", 0);
            Tile tile(x, y, piece);
            board[x][y] = tile;
        }
    }
}

void Board::print() {
    /* for (int y = 0; y < BOARD_HEIGHT; ++y) { */
    /*     for (int x = 0; x < BOARD_WIDTH; ++x) { */
    /*         /1* cout << board[x][y]->print(); *1/ */
    /*         board[x][y].print(); */
    /*     } */
    /* } */
    cout << "hello";
}

