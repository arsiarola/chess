#include <iostream>
#include "piece.h"

using namespace std;
Piece::Piece(std::string name_,  int color_) {
    name = name_;
    color = color_;
}

string Piece::get_name() {
    return name;
}

int main() {
    Piece piece;
    cout << piece.get_name();
    return 0;
}