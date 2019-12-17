#include "pawn.h"

bool Pawn::move(Tile from, Tile to) {
    int x_diff = to.get_x() - from.get_x();
    int y_diff = to.get_y() - from.get_y();


    // Tried to move sideways
    if (x_diff != 0) {
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
