#include "queen.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Queen::Queen(Color color_) {
    color = color_;
    name = "Q";
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

    while (true) {
        if (x_diff > 0) { // right
            pos_tile += 1;
            x_diff -= 1;
        }

        else if (x_diff < 0) { //left
            pos_tile -= 1;
            x_diff += 1;
        }
                
        if (y_diff > 0) { // up
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
        throw "There is same color piece in the path";
    }

    board.assign_tile_by_tile_nums(from_tile, pos_tile);
    
}
