#include <memory>
#include <iostream>

#include "piece.h"
#include "board.h"
#include "tile.h"

using namespace std;

void Board::init_board() {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            Piece *piece = new Piece(to_string(x+ (y * BOARD_HEIGHT)), 0);
            Tile tile(x, y, piece);
            board[x][y] = tile;
        }
    }
}

void Board::print() {
    cout << "  01234567\n\n";
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        cout << y << " ";
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            board[x][y].print();
            cout << " ";
        }
        cout << endl;
    }
}

