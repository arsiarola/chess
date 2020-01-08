#include "rook.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Rook::Rook(Color color_) {
    color = color_;
    name = ROOK;
}

void Rook::move(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
    
    int pos_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();
    int from_tile = from.get_tile_num();

    if (x_diff != 0 && y_diff != 0) {
	throw "Rook can only move horisontally or vertically";
    }

    // make sure the movement is either vertical or horizontal
    if (!((x_diff == 0 && y_diff != 0) || (x_diff != 0 && y_diff == 0))) {
	throw "incorrect movement with rook";
    }

    pos_tile = move_until_dest_or_piece(board, from, destination);
    
    if (board.has_piece(pos_tile) &&
	board.get_piece_color(pos_tile) == color) {
	throw "There is piece infront of rook";
    }

    board.assign_tile_by_tile_nums(from_tile, pos_tile);
}    
    

			
