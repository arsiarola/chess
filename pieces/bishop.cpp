#include "bishop.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Bishop::Bishop(Color color_) {
    color = color_;
    name = BISHOP; 
}

void Bishop::move(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
    
    int pos_tile = from.get_tile_num();
        int from_tile = from.get_tile_num();

    int dest_tile = destination.get_tile_num();

    if (abs(x_diff) != abs(y_diff)) {
	throw "Bishop can only move diagonally";
    }

    pos_tile = move_until_dest_or_piece(board, from, destination);
    
    if (board.has_piece(pos_tile) &&
	board.get_piece_color(pos_tile) == color) {
	throw "Cannot move, there is same coloured piece";
    }

    board.assign_tile_by_tile_nums(from_tile, pos_tile);
}

    
