#include "piece.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"

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

    refresh_screen();
    while (true) {
	ask_for_coordinates(coordinates);
	if (!valid_coordinates(coordinates, from_tile, to_tile)) {
	    refresh_screen("Invalid coordinates");
	    continue;
	}

	// if (!board[0][from_tile].has_piece()) {
	if (!has_piece(from_tile)) {
	    refresh_screen("No piece found to be moved");
	    continue;
	}

	if (turn != board[0][from_tile].get_piece_color()) {
	    refresh_screen("Wrong color piece");
	    continue;
	}

	if (from_tile == to_tile) {
	    refresh_screen("Has to be different tile where to move");
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
    if (tile_num > MAX_TILE_NUM || tile_num < MIN_TILE_NUM) {
	//TODO: maybe add here exception 
	false;
    }
    return board[0][tile_num].has_piece();
}

Color Board::get_piece_color(int tile_num) {
    // TODO: add bound to function 
    return board[0][tile_num].get_piece_color();
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
    if (turn == Color::black) {
	cout << "Black's turn (white background, black pieces)\n";
    }
    else if (turn == Color::white) {
	cout << "White's turn (black background, white pieces)\n";
    }
    
    cout << "Enter the coordinates: ";
    std::getline(std::cin, coordinates);
    for (auto & c: coordinates) c = toupper(c);
}

bool Board::valid_x(int x) {
    // cout << "this is x: " << x << "\n";
    return (x <= BOARD_WIDTH &&  x >= MIN_WIDTH );
}

bool Board::valid_y(int y) {
    // cout << "this is y: " << y << "\n";
    return (y <= BOARD_HEIGHT &&  y >= MIN_HEIGHT );
}

void Board::init_board() {
    // initalize the board with correct tile with pieces in them
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
	for (int x = 0; x < BOARD_WIDTH; ++x) {
	    board[y][x] = init_tile(x, y);
	}
    }
}

int Board::pos_to_num(int x, int y) {
    return x + (y * BOARD_WIDTH);
}

Tile Board::init_tile(int x, int y) {
    int tile_num = pos_to_num(x, y);
    if (BLACK_ROOK(tile_num)) { // black rook
	return Tile(x, y, new Rook(Color::black));
    }

    else if (WHITE_ROOK(tile_num)) { //white rook
	return Tile(x, y, new Rook(Color::white));
    }

    else if (BLACK_KNIGHT(tile_num)) { // black knight
	return Tile(x, y, new Knight(Color::black));
    }

    else if (WHITE_KNIGHT(tile_num)) { // white knight
	return Tile(x, y, new Knight(Color::white));
    }

    else if (BLACK_BISHOP(tile_num)) { // black bishop
	return Tile(x, y, new Bishop(Color::black));
    }

    else if (WHITE_BISHOP(tile_num)) { // white bishop
	return Tile(x, y, new Bishop(Color::white));
    }
    
    else if (BLACK_QUEEN(tile_num)) { // black queen
	return Tile(x, y, new Queen(Color::black));
    }
    
    else if (WHITE_QUEEN(tile_num)) { // white queen
	return Tile(x, y, new Queen(Color::white));
    }

    else if (BLACK_PAWN(tile_num)) { //black pawn
	return Tile(x, y, new Pawn(Color::black));
    }
    
    else if (WHITE_PAWN(tile_num)) { //white pawn
	return Tile(x, y, new Pawn(Color::white));
    }
    
    return Tile(x, y, nullptr);
}


void Board::print() {
    print_letter_row();
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
	print_wall();
	cout << abs(y - BOARD_HEIGHT) << " "; // print so that if y is 0 it will print 8
	print_separator();

	for (int x = 0; x < BOARD_WIDTH; ++x) {
	    board[y][x].print();
	}
	cout << " " << abs(y - BOARD_HEIGHT) << "\n"; // print so that if y is 0 it will print 8
    }
    print_wall();


    print_letter_row();
}

void Board::assign_tile_by_tile_nums(int from_tile, int dest_tile) {
    board[0][dest_tile].assign_tile(&board[0][from_tile]);
}

void Board::print_wall() {
    cout << "  "; // this separation between board and block number
    for (int i = 0; i < ((BOARD_WIDTH-1) * BLOCK_WIDTH - 2); ++i) {
	print_separator();
    }
    cout << "\n";
}

void Board::print_letter_row() {
    char A = 'A';
    cout << "  ";
    for (char i = A; i < A + BOARD_WIDTH; ++i) {
	cout << "  " << i << " ";
    }
    cout << "\n";
}

void print_separator() { cout << P_BLUE << " " << P_RST; }
