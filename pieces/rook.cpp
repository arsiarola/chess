#include "rook.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Rook::Rook(Color color_) {
    color = color_;
    name = "R";
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
    if ((x_diff == 0 && y_diff != 0) || (x_diff != 0 && y_diff == 0)) {
	while (true) {
            if (x_diff > 0) { // right
              pos_tile += 1;
              x_diff -= 1;
	    }

	    else if (x_diff < 0) { //left
              pos_tile -= 1;
              x_diff += 1;
	    }
		
	    else if (y_diff > 0) { // up
              pos_tile += BOARD_WIDTH;
              y_diff -= 1;
	    }

	    else if (y_diff < 0) { // down
              pos_tile -= BOARD_WIDTH;
              y_diff += 1;
	    }
	    
	    // TODO: this is bad checking should do it with calculating new values
            if (pos_tile > MAX_TILE_NUM)
              break;
            if (pos_tile < MIN_TILE_NUM)
              break;
            if (board.has_piece(pos_tile))
              break;
            if (pos_tile == dest_tile)
              break;
        }

        if (board.has_piece(pos_tile) &&
            board.get_piece_color(pos_tile) == color) {
          throw "There is piece infront of rook";
        }
    }

    else throw "incorrect movement with rook";

    board.assign_tile_by_tile_nums(from_tile, pos_tile);
}    
    

			
