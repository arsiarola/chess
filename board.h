#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "tile.h"
#include "tools.h"

#define BOARD_SIZE 64
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

#define MIN_HEIGHT 1
#define MIN_WIDTH 1

#define MAX_TILE_NUM 63
#define MIN_TILE_NUM 0

#define TILE_HOR_PAD 4
#define TILE_WIDTH (TILE_HOR_PAD  * 2 + 1)
#define TILE_VER_PAD 2
#define TILE_HEIGHT (TILE_VER_PAD* 2 + 1)


#define BLACK_ROOK(num)   ((num) == 0 || (num) == 7   ? true : false)
#define BLACK_KNIGHT(num) ((num) == 1 || (num) == 6   ? true : false)
#define BLACK_BISHOP(num) ((num) == 2 || (num) == 5   ? true : false)
#define BLACK_QUEEN(num)  ((num) == 3                 ? true : false)
#define BLACK_KING(num)   ((num) == 4                 ? true : false)
#define BLACK_PAWN(num)   ((num) >= 8 && (num) <= 15  ? true : false)

#define WHITE_ROOK(num)   ((num) == 56 || (num) == 63 ? true : false)
#define WHITE_KNIGHT(num) ((num) == 57 || (num) == 62 ? true : false)
#define WHITE_BISHOP(num) ((num) == 58 || (num) == 61 ? true : false)
#define WHITE_QUEEN(num)  ((num) == 59                ? true : false)
#define WHITE_KING(num)   ((num) == 60                ? true : false)
#define WHITE_PAWN(num)   ((num) >= 48 && (num) <= 55 ? true : false)

void print_separator(int tile_num);

class Board {
public:
    Board() { init_board(); }
    void init_board();
    void print();
    std::string ask_for_move();
    bool has_piece(int tile_num);
    Color get_piece_color(int tile_num);
    void players_turn();
    void assign_tile_by_tile_nums(int from_tile, int dest_tile);
    void refresh_screen(std::string message = "");


    bool is_game_over();
    Color get_turn() { return turn; }
    Color get_winner() { return winner; }
    std::string get_winner_string();
private:
    bool valid_coordinates(std::string coordinates, int &from_num, int &to_num);
    bool valid_x(int x);
    bool valid_y(int y);
    int coordinate_to_tile_num(int x, int y);
    void ask_for_coordinates(std::string &coordinates);
    void switch_turns();
    void print_wall(int row);
    void print_letter_row();
    Tile init_tile(int x, int y);
    int pos_to_num(int x, int y);

    Color winner = Color::none;
    Color turn = black;
    Tile board[BOARD_WIDTH][BOARD_HEIGHT];
};

#endif
