#include <string>
#include "pawn.h"
#include "../tile.h"
#include <iostream>

using std::cout;

Pawn::Pawn(int color_) {
    color = color_;
    name = "P";
}

bool Pawn::move(Tile &from ,Tile &destination, Board &board) {
    cout << "IN move";
    int x_diff = from.get_x() - destination.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = destination.get_y() - from.get_y();


    // Tried to move sideways
    if (x_diff != 0) {
        return false;
    }

    // White tried to move down
    if (y_diff > 0 && color == WHITE) {
        return false;
    }

    // Black tried to move up
    else if (y_diff < 0 && color == BLACK) {
        return false;
    }

    destination.assign_tile(&from);

    return false;
}
