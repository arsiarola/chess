#include <memory>
#include <iostream>

#include "board.h"
#include "tile.h"

using namespace std;

void Board::init_board() {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            Tile tile;
            board[x][y] = tile;
        }
    }
}

void Board::print() {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            /* cout << board[x][y]->print(); */
            board[x][y].print();
        }
    }
}

int main() {
    Board board;
    board.print();
}
