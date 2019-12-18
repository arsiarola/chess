#include <string>
#include "pawn.h"

using namespace std;

Pawn::Pawn(int color_) {
    color = color_;
    name = "P";
}

bool Pawn::move(int from_x, int from_y, int to_x, int to_y, Board &board) {
    int x_diff = from_x - to_x;
    int y_diff = from_y - to_y;;


    // Tried to move sideways
    if (x_diff != 0) {
        return false;
    }

    if (y_diff == UP && color == WHITE) {
        return true;
    }

    else if (y_diff == DOWN && color == BLACK) {
        return true;
    }

    return false;
}
