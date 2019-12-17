#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

#define BOARD_SIZE 64
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

class Board {
public:
    Board() { init_board(); };
    void init_board();
    void print();
private:
    Tile board[BOARD_WIDTH][BOARD_HEIGHT];
};

#endif
