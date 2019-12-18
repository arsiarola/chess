#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "tile.h"

#define BOARD_SIZE 64
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8


class Board {
public:
    Board() { init_board(); };
    void init_board();
    void print();
    std::string ask_for_move();
    void players_turn();
private:
    int coordinate_to_tile_num(std::string coordinates);
    void split_coordinates(std::string coordinates, std::string from, std::string to);
    void ask_for_coordinates(std::string coordinates);
    bool coordinates_to_int(std::string coordinates, int &, int &, int &, int &);
    Tile board[BOARD_WIDTH][BOARD_HEIGHT];
};

#endif
