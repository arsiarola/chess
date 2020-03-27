#include "pawn.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Pawn::Pawn(Color color_) {
    color = color_;
    name = PAWN;
}

void Pawn::move(Tile &from ,Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down

    int from_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();
    Color turn = board.get_turn();

    // will throw if there is error
    is_correct_direction(from, destination);

    if (abs(x_diff) > 1) { // Tried to move sideways too much
        throw "Pawn cannot move sideways";
    }

    // check for eating meaning one sideways and one up or down depending on the color
    if (color == Color::white) {
        if (can_white_eat(from, destination, board)) {
            move_pawn_on_board(from, destination);
            return;
        }
    }
    else if (color == Color::black) {
        if (can_black_eat(from, destination, board)) {
            move_pawn_on_board(from, destination);
            return;
        }

    }

    // Check if it's first move and the is moved by two
    if (first_move && abs(y_diff) == 2 && abs(x_diff) == 0 && !(is_piece_in_front(from, destination, board))) {
        move_pawn_on_board(from, destination);
        return;
    }

    // Since first move has been checked pawn can only move by one vertically
    if (abs(y_diff) > 1) {
        throw "Pawn can only move one step";
    }

    // Since eating check has been done now we can't move sideways
    if (abs(x_diff) > 0) {
        throw "Pawn cannot move sideways";
    }

    if (is_piece_in_front(from, destination, board)) {
        throw "There is piece infront of pawn, cannot move there";
    }

    move_pawn_on_board(from, destination);
}


bool Pawn::is_piece_in_front (Tile &from, Tile &destination, Board &board) {
    // int from_tile = from.get_tile_num();
    // int dest_tile = destination.get_tile_num();
    // if (dest_tile > from_tile) {
    // 	while (dest_tile > from_tile) {
    // 	    cout << "dest_tile = " << dest_tile << "\n";
    // 	    if (board.has_piece(dest_tile)) return true;
    // 	    dest_tile -= BOARD_WIDTH;
    // 	}
    // }

    // else if (dest_tile < from_tile) {
    // 	while (dest_tile < from_tile) {
    // 	    cout << "dest_tile = " << dest_tile << "\n";
    // 	    if (board.has_piece(dest_tile)) return true;
    // 	    dest_tile += BOARD_WIDTH;
    // 	}
    // }


    int pos_tile = move_until_dest_or_piece(board, from, destination);
    if (board.has_piece(pos_tile)) return true;
    return false;
}

// check that the direction is correct according to the color
bool Pawn::is_correct_direction(Tile &from, Tile &destination) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down

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

// Test for eating since it involves horizontal movement
bool Pawn::can_white_eat(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
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
            return true;
        }
    }

    return false;
}

bool Pawn:: can_black_eat(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
    int dest_tile = destination.get_tile_num();

    // In no case can black move up
    if (y_diff < 0) {
        throw "Black pawn cannot move up";
    }

    // Lets do the eating checking quickly so that we can exclude side movement afterwards
    if (y_diff == 1 && abs(x_diff) == 1 && destination.has_piece()) {
        // different color piece that it tries to eat
        if (destination.get_piece_color() != color) {
            return true;
        }
    }

    return false;
}

void Pawn::move_pawn_on_board(Tile &from, Tile &destination) {
    destination.assign_tile(&from);
    first_move = false;
}
