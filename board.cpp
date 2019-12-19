#include <memory>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string.h>

#include "pieces/pawn.h"
#include "piece.h"
#include "board.h"
#include "tile.h"
#include "macros.h"
#include "tools.h"

using std::cout;

void Board::players_turn() {
    std::string coordinates;
    int from_tile;
    int to_tile;

    while (true) {
        ask_for_coordinates(coordinates);
        if (!valid_coordinates(coordinates, from_tile, to_tile)) {
            refresh_screen("Invalid coordinates\n");
            continue;
        }
        cout << "from: " << from_tile << "\n";
        cout << "to: " << to_tile << "\n";

        if (board[from_tile]->get_piece() == nullptr) {
            refresh_screen("No piece found to be moved\n");
            continue;
        }

        board[from_tile]->move(board[from_tile], board[to_tile],

        break;
    }
}

void Board::refresh_screen(std::string message) {
            system("clear");
            print();
            cout << message;
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
    cout << "x_ = " << x_ << "\n";
    cout << "y_ = " << y_ << "\n";
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
    cout << "this is x: " << x << "\n";
    return (x <= MAX_WIDTH &&  x >= MIN_WIDTH );
}

bool Board::valid_y(int y) {
    cout << "this is y: " << y << "\n";
    return (y <= MAX_HEIGHT &&  y >= MIN_HEIGHT );
}

void Board::init_board() {
    int pawn_place = 1;

    // initalize empty spots and pawns
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // upper row for pawns
            if (y == pawn_place) {
                Tile tile(x, y, new Pawn(BLACK));
                board[x][y] = tile;
            }

            // lower row for pawns
            else if (y == BOARD_HEIGHT-1 - pawn_place) {
                Tile tile(x, y, new Pawn(WHITE));
                board[x][y] = tile;
            }

            else {
                Tile tile(x, y, nullptr);
                board[x][y] = tile;
            }
        }
    }
}

void Board::print() {
    cout << "  abcdefgh\n\n";
    for (int y = BOARD_HEIGHT-1; y >= 0; --y) {
        cout << y+1 << " ";
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            board[x][y].print();
        }
        cout << " " << y+1 << "\n";
    }
    cout << "  abcdefgh\n";
}

