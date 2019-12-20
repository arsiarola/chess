#include <string>
#include "pawn.h"
#include "../tile.h"

using namespace std;

Pawn::Pawn(int color_) {
    color = color_;
    name = "P";
}

bool Pawn::move(Tile &from ,Tile &to, Board &board) {
    int x_diff = from.get_x() - to.get_x();
    // Negative y_diff to move up and positive for down
    int y_diff = to.get_y() - from.get_y();


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

    to.assign_piece(this);

    return false;
}
