#include "piece.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"

#include "board.h"
#include "tile.h"
#include "tools.h"

#include <memory>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using std::cout;


// Everything that has to do when player is inputting coordinates
void Board::players_turn() {
    std::string coordinates;
    int from_tile;
    int to_tile;

    refresh_screen();
    while (true) {
        ask_for_coordinates(coordinates);
        // Check that the coordinates are within bounds
        if (!valid_coordinates(coordinates, from_tile, to_tile)) {
            refresh_screen("Invalid coordinates");
            continue;
        }

        // Check whether the first coordinate that is to be moved has a piece
        if (!has_piece(from_tile)) {
            refresh_screen("No piece found to be moved");
            continue;
        }

        // Check the color of the piece
        if (turn != board[0][from_tile].get_piece_color()) {
            refresh_screen("Wrong color piece");
            continue;
        }

        if (from_tile == to_tile) {
            refresh_screen("Has to be different tile where to move");
            continue;
        }

        // Use polymorphism to call piece's move function. Every type of
        // piece has it's own implemented move function that will throw an exception
        // with an message if the move was incorrect
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

// Switch turns black -> white or white -> black
void Board::switch_turns() {
    if (turn == Color::black) {
        turn = Color::white;
    }
    else {
        turn = Color::black;
    }
}

// check whether a given tile in board has a piece, by the tile number
bool Board::has_piece(int tile_num) {
    if (tile_num > MAX_TILE_NUM || tile_num < MIN_TILE_NUM) {
        //TODO: maybe add here exception
        return false;
    }
    return board[0][tile_num].has_piece();
}

// Get color of a piece by tile number
Color Board::get_piece_color(int tile_num) {
    // TODO: Not sure if here should be done some kind of checking and how to return the error
    return board[0][tile_num].get_piece_color();
}


// Clear screen, print board and out put a message that default to empty string
void Board::refresh_screen(std::string message) {
    system("clear");
    print();
    cout << message << "\n";
}

// Check whether user inputted string contains valid coordinates
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

    // all checking done we can assign the values to the parameters since they are references
    from_num = coordinate_to_tile_num(from_x, from_y);
    to_num = coordinate_to_tile_num(to_x, to_y);

    return true;
}

// X and Y numbers to a tile number
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

    // TODO: add exit optioin
    cout << "Enter the coordinates separated by space (for example \"a1 b2\"): ";
    std::getline(std::cin, coordinates);
    for (auto & c: coordinates) c = toupper(c); // turn coordinates to uppercase
}

// check if x value is within bounds
bool Board::valid_x(int x) {
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

// return tile number from x and y
int Board::pos_to_num(int x, int y) {
    return x + (y * BOARD_WIDTH);
}

// return whether game is over
bool Board::is_game_over() {
    if (winner == Color::none) {
        return false;
    }
    return true;
}

// return winner in string format
std::string Board::get_winner_string() {
    if (winner == Color::white) return "white";
    if (winner == Color::black) return "black";
    return "";
}

// return correct tile based on coordinates
// for every type of piece there is a macro that takes tile number and
// returns whether that tile is correct
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

    else if (BLACK_KING(tile_num)) { // black king
        return Tile(x, y, new King(Color::black));
    }

    else if (WHITE_KING(tile_num)) { // white king
        return Tile(x, y, new King(Color::white));
    }

    else if (BLACK_PAWN(tile_num)) { //black pawn
        return Tile(x, y, new Pawn(Color::black));
    }

    else if (WHITE_PAWN(tile_num)) { //white pawn
        return Tile(x, y, new Pawn(Color::white));
    }

    // every type of piece has been checked so create an empty tile that meaning
    // piece pointer is nullptr
    return Tile(x, y, nullptr);
}

// Print the board
void Board::print() {
    print_letter_row();
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        print_wall(y);
        cout << abs(y - BOARD_HEIGHT) << " "; // print so that if y is 0 it will print 8
        cout << " "; // between numbers and actual board

        for (int x = 0; x < BOARD_WIDTH; ++x) {
            board[y][x].print();
        }
        cout << " " << abs(y - BOARD_HEIGHT) << "\n"; // print so that if y is 0 it will print 8
        print_wall(y);
    }

    print_letter_row();
}

// move piece by its tile number to some other tile
void Board::assign_tile_by_tile_nums(int from_tile, int dest_tile) {
    if (!board[0][from_tile].has_piece()) {
        // TODO: maybe better checking here
        cout << "No piece found\n";
        return;
    }

    if (board[0][dest_tile].get_piece_name() == KING) {
        winner = board[0][from_tile].get_piece_color();
    }
    board[0][dest_tile].assign_tile(&board[0][from_tile]);
}

// print horisontal wall that is the width of the board by separators
void Board::print_wall(int row) {
    cout << "   "; // this separation between board and block number
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
                print_separator(i + 8 * row);
        }
    }
    cout << "\n";
}

// print a row of the horisintal coordinates matching the width of the
// board and the correspondig tiles
void Board::print_letter_row() {
    char A = 'A';
    cout << " ";
    for (int j = 0; j < BLOCK_WIDTH / 2; ++j) cout << " ";
    for (char i = A; i < A + BOARD_WIDTH; ++i) {
        for (int j = 0; j < BLOCK_WIDTH / 2; ++j) cout << " ";
        cout << i;
        for (int j = 0; j < BLOCK_WIDTH / 2; ++j) cout << " ";
    }
    cout << "\n";
}

// Print one separator that is the structure of the board
// with these the board grid will be made
void print_separator(int tile_num) {
    cout << tile_num_to_bg(tile_num) << " " << RESET;
}
