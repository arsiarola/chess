#include <string>
#include <iostream>

#include "piece.h"
#include "board.h"
#include "macros.h"

#ifndef COLORS_
#define COLORS_

/* FOREGROUND */
#define P_RST  "\033[0m"
#define P_BLC  "\033[1;30m"
#define P_WHT  "\033[1;37m"

#endif  /* _COLORS_ */

using namespace std;
Piece::Piece(std::string name_,  int color_) {
    name = name_;
    color = color_;
}

string Piece::get_name() {
    return name;
}


bool Piece::move(int from_x, int from_y, int to_x, int to_y, Board &board){
    return false;
}

void Piece::print() {
    if (color == BLACK) {
        cout << P_BLC << name << P_RST;
    }
    else {
        cout << P_WHT << name << P_RST;
    }
}
