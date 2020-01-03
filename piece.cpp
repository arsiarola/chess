#include <string>
#include <iostream>

#include "piece.h"
#include "board.h"
#include "macros.h"

#ifndef COLORS_
#define COLORS_

/* FOREGROUND */
#define P_RST  "\033[0m"
#define P_BLC  "\033[1;30;47m"
#define P_WHT  "\033[1;37;40m"

#endif  /* COLORS_ */

using namespace std;
Piece::Piece(std::string name_,  Color color_) {
    name = name_;
    color = color_;
}

Piece::Piece(const Piece &piece) {
    name = piece.name;
    color = piece.color;
}

void Piece::print() {
    if (color == Color::black) {
        cout << P_BLC << name << P_RST;
    }
    else if (color == Color::white) {
        cout << P_WHT << name << P_RST;
    }
}
