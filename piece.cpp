#include <string>
#include <iostream>

#include "piece.h"
#include "board.h"
#include "tools.h"


Piece::Piece(std::string name_,  Color color_) {
    name = name_;
    color = color_;
}

Piece::Piece(const Piece &piece) {
    name = piece.name;
    color = piece.color;
}

// print a piece according to it's color with color print codes from tools.h
// black pieces have white background and black foreground, otherway for whites
void Piece::print() {
    if (color == Color::black) {
        std::cout << P_BLC << name << P_RST;
    }
    else if (color == Color::white) {
        std::cout << P_WHT << name << P_RST;
    }
}


// Two functions for calculating  difference in x and y axis between two tiles
// - X_diff for left, + right
int Piece::get_x_diff(Tile &from, Tile &destination) {
    return destination.get_x() - from.get_x();
}

// - y_diff for up, + positive down
int Piece::get_y_diff(Tile &from, Tile &destination) {
    return destination.get_y() - from.get_y();
}

// move piece untill it hits another piece or is in the destination
int Piece::move_until_dest_or_piece(Board &board, Tile &from, Tile &destination) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
    
    int pos_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();

    while (true) {
	if (x_diff > 0) { // right
	    x_diff -= 1;
	    pos_tile += 1;
	}

	if (x_diff < 0) { //left
	    x_diff += 1;
	    pos_tile -= 1;
	}
		
	if (y_diff > 0) { // up
	    y_diff -= 1;
	    pos_tile += BOARD_WIDTH;
	}

	if (y_diff < 0) { // down
	    y_diff += 1;
	    pos_tile -= BOARD_WIDTH;
	}

	// this movement out of bounds shouldn't happen
	if (pos_tile > MAX_TILE_NUM || pos_tile < MIN_TILE_NUM)
	    throw "movement out of bounds";
	
	if (check_if_dest_or_piece(board, pos_tile, dest_tile)) {
	    return pos_tile;
	}
    }
    return 0;
}

// test if destination or another piece has been reached
bool Piece::check_if_dest_or_piece(Board &board, int pos_tile, int dest_tile) {
    if (board.has_piece(pos_tile)) return true;
    if (pos_tile == dest_tile)     return true;
    return false;
}
