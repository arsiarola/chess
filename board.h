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

#define MAX_TILE_NUM 63
#define MIN_TILE_NUM 0

#define BLACK_ROOK(num) ((num) == 0 || (num) == 7 ? true : false)
#define WHITE_ROOK(num) ((num) == 56 || (num) == 63 ? true : false)

#define BLACK_KNIGHT(num) ((num) == 1 || (num) == 6 ? true : false)
#define WHITE_KNIGHT(num) ((num) == 57 || (num) == 62 ? true : false)

#define BLACK_PAWN(num) ((num) >= 8 && (num) <= 15 ? true : false)
#define WHITE_PAWN(num) ((num) >= 48 && (num) <= 55 ? true : false)





class Board {
public:
    Board() { init_board(); };
    void init_board();
    void print();
    std::string ask_for_move();
    bool has_piece(int tile_num);
    Color get_piece_color(int tile_num);
    void players_turn();
    void assign_tile_by_tile_nums(int from_tile, int dest_tile);
  
    Color get_turn() { return turn; };
private:
    Color turn = black;
    bool valid_coordinates(std::string coordinates, int &from_num, int &to_num);
    bool valid_x(int x);
    bool valid_y(int y);
    int coordinate_to_tile_num(int x, int y);
    void ask_for_coordinates(std::string &coordinates);
    void refresh_screen(std::string message = "");
    void switch_turns();

    Tile init_tile(int x, int y);
    int pos_to_num(int x, int y);

    Tile board[BOARD_WIDTH][BOARD_HEIGHT];
};

#endif
