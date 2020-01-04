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

    if (turn != color) {
	cout << "Wrong color pawn\n";
	return false;
    } 

    // TODO: Create bound checking function in board class and call it here for
    // from and destination

    if (x_diff > 1) { // Tried to move sideways too much 
	cout << "Pawn cannot move sideways\n";
	return false;
    } 

    if (color == Color::white) {
	return move_white(from, destination);	
    }
    else {
	return move_black(from, destination);
    }

    destination.assign_tile(&from);
    return true;
}

bool Pawn::move_black(Tile &from, Tile &destination) {
    if (color != Color::black) {
	cout << "Wrong color\n";
	return false;
    }
    
    int x_diff = from.get_x() - destination.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();

    if (y_diff < 0) {
	cout << "Black cannot move up\n";
	return false;  
    }

    if (y_diff > 1) {
	cout << "Pawn can only move one step\n";
	return false;
    }
    
    if (y_diff == 1 && abs(x_diff) == 1 && destination.has_piece()) {
	// different color piece that it tries to eat
	if (destination.get_piece_color() != color) { 
	    destination.assign_tile(&from);
	    return true;
	}
    }

    if (abs(x_diff > 0)) {
	cout << "Pawn cannot move sideways\n";
	return false;
    }
    
    if (destination.has_piece()) {
	cout << "Other piece infront of pawn, cannot move there\n";
	return false ;
    }

    destination.assign_tile(&from);
    return true;
}

bool Pawn::move_white(Tile &from, Tile &destination) {
    if (color != Color::white) {
	cout << "Wrong color\n";
	return false;
    }
    
    int x_diff = from.get_x() - destination.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();

    int dest_tile = destination.get_tile_num();
   
    if (y_diff > 0) {
	cout << "White cannot move down\n";
	return false;  // White tried to move down
    }

    if (first_move) {
	if (!destination.has_piece() && 
    }
    // TODO: First turn can move two up/down
    if (y_diff < -1) {
	cout << "Pawn can only move one step\n";
	return false;
    }
    
    if (y_diff == -1 && abs(x_diff) == 1 && destination.has_piece()) {
	// different color piece that it tries to eat
	if (destination.get_piece_color() != color) {
	    destination.assign_tile(&from);
	    return true;
	}
    }
	
    if (abs(x_diff) > 0) {
	cout << "Pawn cannot move sideways\n";
	return false; // can't move sideways anymore since eating has been tested
    }
    
    if (destination.has_piece()) {
	cout << "There is piece infront of pawn, cannot move there\n";
	return false;
    }
    
    destination.assign_tile(&from);
    return true;
}

