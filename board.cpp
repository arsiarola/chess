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

void Board::players_turn() {
    std::string coordinates;
    std::string from;
    std::string to;
    int from_tile;
    int to_tile;

    while (true) {
        ask_for_coordinates(coordinates);
        if (!valid_coordinates(coordinates, from_tile, to_tile)) {
            system("clear");
            print();
            std::cout << "Please Enter two valid coordinates e.g. a1 b1\n";
        }
        std::cout << "from: " << from_tile << "\n";
        std::cout << "to: " << to_tile << "\n";

    }
}

bool Board::valid_coordinates(std::string coordinates, int &from_num, int &to_num) {
    if (coordinates.size() < 5) {
        return false;
    }

    char from_x = coordinates[0];
    int from_y = coordinates[1];
    char to_x = coordinates[3];
    int to_y = coordinates[4];

    if (!valid_y(from_y) || !valid_y(to_y)) {
        return false;
    }

    if (!valid_x(from_x) || !valid_x(to_x)) {
        return false;
    }

    from_num = coordinate_to_tile_num(from_x, from_y);
    to_num = coordinate_to_tile_num(to_x, to_y);

    return true;
}

int coordinate_to_tile_num(int x_, int y_) {
    int x = x_ - MIN_WIDTH;
    int y = abs(y_ - BOARD_HEIGHT);
    return x + y;
}

void split_coordinates(std::string coordinates, std::string from, std::string to) {
    if (!valid_coordinates(coordinates)) {
        return;
    }

    from = coordinates[0] + coordinates[1];
    to = coordinates[3] + coordinates[5];
}

void Board::ask_for_coordinates(std::string coordinates) {
    std::cout << "Enter the coordinates: ";
    std::cin >> coordinates;
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
    std::cout << "  abcdefgh\n\n";
    for (int y = BOARD_HEIGHT-1; y >= 0; --y) {
        std::cout << y+1 << " ";
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            board[x][y].print();
        }
        std::cout << " " << y+1 << "\n";
    }
    std::cout << "  abcdefgh\n";
}

