#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "tile.h"
#include "tools.h"

#define BOARD_SIZE 64
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

#define MAX_HEIGHT 8
#define MIN_HEIGHT 1
#define MAX_WIDTH 8
#define MIN_WIDTH 1



class Board {
public:
    Board() { init_board(); };
    void init_board();
    void print();
    std::string ask_for_move();
    void players_turn();
  
    Color get_turn() { return turn; };
private:
    void refresh_screen(std::string message = "");
    int coordinate_to_tile_num(int x, int y);
    bool valid_coordinates(std::string coordinates, int &from_num, int &to_num);
    void ask_for_coordinates(std::string &coordinates);
    bool valid_y(int y);
    bool valid_x(int x);
    Color turn = black;

    Tile board[BOARD_WIDTH][BOARD_HEIGHT];
};

#endif
