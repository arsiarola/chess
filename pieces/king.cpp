#include "king.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

King::King(Color color_) {
    color = color_;
    name = KING;
}

void King::move(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down

    int from_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();

    if (abs(x_diff) > 1 || abs(y_diff) > 1) {
        throw "King can only move one step";
    }

    if (board.has_piece(dest_tile) &&
        board.get_piece_color(dest_tile) == color) {
        throw "There is same color piece in the path";
    }

    board.assign_tile_by_tile_nums(from_tile, dest_tile);

}
