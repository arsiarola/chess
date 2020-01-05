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


void Pawn::move(Tile &from ,Tile &destination, Board &board) {
    int x_diff = from.get_x() - destination.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();

    int from_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();
    Color turn = board.get_turn();

    if (turn != color) {
	throw "Wrong color pawn";
    } 

    if (dest_tile == from_tile) {
	throw "Move has to be a different tile from original position";
    }
    
    // will throw if there is error
    if (!is_correct_direction(from, destination)) return; 
    
    // TODO (Maybe, not sure if it belongs here)
    // ceate bound checking function in board class and call it here for  from and destination

    if (abs(x_diff) > 1) { // Tried to move sideways too much 
	throw "Pawn cannot move sideways";
    } 

    if (color == Color::white) {
	can_move_white(from, destination, board);
    }
    else if (color == Color::black) {
	can_move_black(from, destination, board);
    }

    // We can check first move here since the can_move_ will check correct direction
    if (first_move && abs(y_diff) == 2 && abs(x_diff) == 1 && !(is_piece_in_front(from, destination, board))) {
	destination.assign_tile(&from);
	first_move = false;
	return;
    }
    
    if (abs(y_diff) > 1) {
	throw "Pawn can only move one step";
    }
    
    // Since eating check has been done now we can't move sideways
    if (abs(x_diff) > 0) {
	throw "Pawn cannot move sideways\n";
    }
    
    if (is_piece_in_front(from, destination, board)) {
	throw "There is piece infront of pawn, cannot move there\n";
    }
    
    destination.assign_tile(&from);
}

bool Pawn::is_piece_in_front (Tile &from, Tile &destination, Board &board) {
    int from_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();

    if (dest_tile > from_tile) {
	while (dest_tile> from_tile) {
	    cout << "dest_tile = " << dest_tile << "\n";
	    if (board.has_piece(dest_tile)) return true;
	    dest_tile -= BOARD_WIDTH;
	}
    }

    else if (dest_tile < from_tile) {
	while (dest_tile < from_tile) {
	    cout << "dest_tile = " << dest_tile << "\n";
	    if (board.has_piece(dest_tile)) return true;
	    dest_tile += BOARD_WIDTH;
	}
    }

    return false;
}

bool Pawn::is_correct_direction(Tile &from, Tile &destination) {
    int x_diff = from.get_x() - destination.get_x();
    int y_diff = destination.get_y() - from.get_y(); // - move up and + move down

    if (color == Color::white) {
	if (y_diff > 0) throw "White pawn cannot move down";
	return false;
    }
    
    else if (color == Color::black) {
	if(y_diff < 0) throw "Black pawn cannot move up";
	return false;
    }

    return true;
}

bool Pawn::can_move_white(Tile &from, Tile &destination, Board &board) {
    int x_diff = from.get_x() - destination.get_x();
    int y_diff = destination.get_y() - from.get_y(); // - move up and + move down
    int dest_tile = destination.get_tile_num();
    
    // In no case can white move down
    if (y_diff > 0) {
	throw "White pawn cannot move down";
	return false;
    }
   
    // Lets do the eating checking quickly so that we can exclude side movement afterwards
    if (y_diff == -1 && abs(x_diff) == 1 && destination.has_piece()) {
	// different color piece that it tries to eat
	if (destination.get_piece_color() != color) {
	    destination.assign_tile(&from);
	    return true;
	}
    }

    return false;
}

bool Pawn::can_move_black(Tile &from, Tile &destination, Board &board) {
    int x_diff = from.get_x() - destination.get_x();
    int y_diff = destination.get_y() - from.get_y(); // - move up and + move down
    int dest_tile = destination.get_tile_num();
    
    // In no case can black move up
    if (y_diff < 0) {
	throw "Black pawn cannot move up";
    }
   
    // Lets do the eating checking quickly so that we can exclude side movement afterwards
    if (y_diff == 1 && abs(x_diff) == 1 && destination.has_piece()) {
	// different color piece that it tries to eat
	if (destination.get_piece_color() != color) {
	    destination.assign_tile(&from);
	    return true;
	}
    }

    return false;
}

