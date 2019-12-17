#include "pawn.h"

bool Pawn::move(int x_, int y_) {
    int diff = x_ - x;
    int y_diff = y_ - y;


    // Tried to move sideways
    if (color x_diff != 0) {
        return false;
    }

    if (y_diff == UP && color = WHITE) {
        return true;
    }

    else if (y_diff == DOWN && color = BLACK) {
        return true;
    }

    return false;
}
