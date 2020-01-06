#ifndef PIECE_H
#define PIECE_H

class Piece;
class Board;
class Tile;

#include <string>
#include "macros.h"
#include "tools.h"

class Piece {
public:
    Piece(std::string = "", Color color = black);
    Piece(const Piece &piece);
    // remember to declace all virtual functions like here we have "= 0"
    //other wise will get weird undefined reference to vtable
    virtual void move(Tile &from ,Tile &to, Board &board) = 0; 
    
    std::string get_name() { return name; };
    Color get_color () { return color; };
    void print();
protected:
    int get_x_diff(Tile &from, Tile &destination);
    int get_y_diff(Tile &from, Tile &destination);
    std::string name;
    Color color;
};

#endif
