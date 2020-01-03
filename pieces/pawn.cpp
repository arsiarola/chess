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

    // Tried to move wrong pieces
    if (turn != color) { return false; }

    // TODO: Create bound checking function in board class and call it here for
    // from and destination

    // Tried to move sideways too much even for eating other piece
    if (x_diff > 1) { return false; }
    
    if (color == Color::white) {
	// White tried to move down
	if (y_diff > 0) { return false; }

	// TODO: First turn can move two up/down
	if (y_diff < -1) { return false; };
	if (y_diff == 1 && abs(x_diff) == 1 && destination.has_piece()) {
	// different color piece that it tries to eat
	    if (destination.piece->get_color != color) {
		destination.assign_tile(&from);
		return true;
	    }
	}
    }

    if (color == Color::black) {
	// Black tried to move up
	if (y_diff < 0) { return false; }

	if (y_diff > 1) { return false; };
	if (y_diff == -1 && abs(x_diff) == 1 && destination.has_piece()) {
	    // different color piece that it tries to eat
	    if (destination.piece->get_color != color) { 
		destination.assign_tile(&from);
		return true;
	    }
	}
    }


    if (x_diff == 1)

	// Tried to move more than one block
	if (abs(ydiff) > 1) { return false; }
    

    destination.assign_tile(&from);

    return true;
}
