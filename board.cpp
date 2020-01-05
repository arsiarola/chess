#include "pieces/pawn.h"
#include "piece.h"
#include "board.h"
#include "tile.h"
#include "macros.h"
#include "tools.h"

#include <memory>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using std::cout;

void Board::players_turn() {
    std::string coordinates;
    int from_tile;
    int to_tile;

    print();
    while (true) {
	ask_for_coordinates(coordinates);
	if (!valid_coordinates(coordinates, from_tile, to_tile)) {
	    refresh_screen("Invalid coordinates\n");
	    continue;
	}
	cout << "from: " << from_tile << "\n";
	cout << "to: " << to_tile << "\n";

	if (!board[0][from_tile].has_piece()) {
	    refresh_screen("No piece found to be moved\n");
	    continue;
	}

	try {
	    board[0][from_tile].move(board[0][to_tile], *this);
	}
	catch (const char *message) {
	    refresh_screen(message);
	    continue;
	}
	
	switch_turns();
	break;
    }
}

void Board::switch_turns() {
    if (turn == Color::black) {
	turn = Color::white;
    }
    else {
	turn = Color::black;
    }
}

bool Board::has_piece(int tile_num) {
    return board[0][tile_num].has_piece();
}

void Board::refresh_screen(std::string message) {
    system("clear");
    print();
    cout << message << "\n";
}

bool Board::valid_coordinates(std::string coordinates, int &from_num, int &to_num) {
    if (coordinates.length() < 5) {
	cout << "Input string was too short\n";
	return false;
    }

    // having - '0' will convert from char to int
    // for x axel we need -16 since it's an uppercase letter and we want e.g. A to represent 1
    int from_x = coordinates[0] - 16 - '0';
    int to_x = coordinates[3]   - 16 - '0';

    int from_y = coordinates[1] - '0';
    int to_y = coordinates[4]   - '0';

    if (!valid_x(from_x) || !valid_x(to_x)) {
	return false;
    }

    if (!valid_y(from_y) || !valid_y(to_y)) {
	return false;
    }

    
    from_num = coordinate_to_tile_num(from_x, from_y);
    to_num = coordinate_to_tile_num(to_x, to_y);

    return true;
}

int Board::coordinate_to_tile_num(int x_, int y_) {
    int x = x_ - MIN_WIDTH;
    int y = abs(y_ - BOARD_HEIGHT);
    return x + (y * BOARD_WIDTH);
}

void Board::ask_for_coordinates(std::string &coordinates) {
    cout << "Enter the coordinates: ";
    std::getline(std::cin, coordinates);
    for (auto & c: coordinates) c = toupper(c);
}

bool Board::valid_x(int x) {
    // cout << "this is x: " << x << "\n";
    return (x <= MAX_WIDTH &&  x >= MIN_WIDTH );
}

bool Board::valid_y(int y) {
    // cout << "this is y: " << y << "\n";
    return (y <= MAX_HEIGHT &&  y >= MIN_HEIGHT );
}

void Board::init_board() {
    int pawn_place = 1;

    // initalize empty spots and pawns
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
	for (int x = 0; x < BOARD_WIDTH; ++x) {
	    Tile tile;
	    // upper row for black pawns
	    if (y == pawn_place) {
 		tile = Tile(x, y, new Pawn(Color::black));
	    }

	    // lower row for white pawns
	    else if (y == BOARD_HEIGHT-1 - pawn_place) {
		tile = Tile(x, y, new Pawn(Color::white));
	    }

	    else {
		tile = Tile(x, y, nullptr);
	    }
	    
	    board[y][x] = tile;
	}
    }
}

void Board::print() {
    cout << "  abcdefgh\n";
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
	cout << abs(y - BOARD_HEIGHT) << " "; // print so that if y is 0 it will print 8

	for (int x = 0; x < BOARD_WIDTH; ++x) {
	    board[y][x].print();
	}
	cout << " " << abs(y - BOARD_HEIGHT) << "\n"; // print so that if y is 0 it will print 8
    }

    cout << "  abcdefgh\n";
}
