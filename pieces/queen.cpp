#include "queen.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Queen::Queen(Color color_) {
    color = color_;
    name = QUEEN;
}

void Queen::move(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
    
    int pos_tile = from.get_tile_num();
    int from_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();

    // Diagonal movement
    if (x_diff != 0 && y_diff != 0) {
        if (abs(x_diff) != abs(y_diff)) {
            throw "Queen can move horizontally, vertically or diagonally";
        }
    }

    pos_tile = move_until_dest_or_piece(board, from, destination);

    if (board.has_piece(pos_tile) &&
	board.get_piece_color(pos_tile) == color) {
	throw "There is same color piece in the path";
    }

    board.assign_tile_by_tile_nums(from_tile, pos_tile);
    
}
