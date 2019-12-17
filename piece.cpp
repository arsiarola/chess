#include <iostream>
#include "piece.h"
#define WHITE 1
#define BLACK 0

using namespace std;
Piece::Piece(std::string name_, int x_, int y_, int color_) {
    name = name_;
    x = x_;
    y = y_;
    color = color_;
}

string Piece::get_name() {
    return name;
}

int Piece::get_x() {
    return x;
}

int Piece::get_y() {
    return y;
}

int main() {
    Piece piece;
    cout << piece.get_name();
    return 0;
}
