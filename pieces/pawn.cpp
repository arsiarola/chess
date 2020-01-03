#include "pawn.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Pawn::Pawn(Color color_) {
    color = color_;
    name = "P";
}


bool Pawn::move(Tile &from ,Tile &destination, Board &board) {
    int x_diff = from.get_x() - destination.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();

    Color turn = board.get_turn();

    if (turn != color) { return false; } // Tried to move wrong pieces

    // TODO: Create bound checking function in board class and call it here for
    // from and destination

    if (x_diff > 1) { return false; } // Tried to move sideways too much 

    if (color == Color::white) {
	return move_white(from, destination);	
    }
    else {
	return move_black(from, destination);
    }

    

    

    


    destination.assign_tile(&from);
    return true;
}

bool Pawn::move_black(Tile $fomr, Tile &destination) {
    if (color != Color::black) return false;
    
    int x_diff = from.get_x() - destination.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();

    if (color == Color::black) {
	// Black tried to move up
	if (y_diff < 0) { return false; }

	if (y_diff > 1) { return false; };
	if (y_diff == -1 && abs(x_diff) == 1 && destination.has_piece()) {
	    // different color piece that it tries to eat
	    if (destination.get_piece_color() != color) { 
		destination.assign_tile(&from);
		return true;
	    }
	}
    }
}

bool Pawn::move_white(Tile &from, Tile &destination) {
    int x_diff = from.get_x() - destination.get_x();
    
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();

    if (color != Color::white) return false;

    if (y_diff > 0) { return false; } // White tried to move down

    // TODO: First turn can move two up/down
    if (y_diff < -1) { return false; }; // White tried to move more than one
    if (y_diff == 1 && abs(x_diff) == 1 && destination.has_piece()) {
	// different color piece that it tries to eat
	if (destination.get_piece_color() != color) {
	    destination.assign_tile(&from);
	    return true;
	}
    }
	
    if (x_diff > 0) { return false; }; // can't move sideways anymore since eating has been tested
    destination.assign_tile(&from);
    return true;
}

int Pawn::
