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
    std::string from;
    std::string to;
    int from_tile;
    int to_tile;

    while (true) {
        ask_for_coordinates(coordinates);
        if (!valid_coordinates(coordinates, from_tile, to_tile)) {
            /* system("clear"); */
            /* print(); */
            cout << "Please Enter two valid coordinates e.g. a1 b1\n";
            continue;
        }
        cout << "from: " << from_tile << "\n";
        cout << "to: " << to_tile << "\n";

        break;
    }
}

bool Board::valid_coordinates(std::string coordinates, int &from_num, int &to_num) {
    if (coordinates.length() < 5) {
        cout << "Input string was too short\n";
        return false;
    }

// having - '0' will basically convert from char to int
    int from_x = coordinates[0] - 16 - '0';
    int from_y = coordinates[1] - '0';
    int to_x = coordinates[3] - 16 - '0';
    int to_y = coordinates[4] - '0';

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

