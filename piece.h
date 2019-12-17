#ifndef PIECE_H
#define PIECE_H

#include <string>

#define WHITE 1
#define BLACK 0

class Piece {
public:
    Piece(std::string = "", int color = 0);
    Piece(const Piece &p);
    virtual bool move();
    std::string get_name();
    int get_x();
    int get_y();
protected:
    std::string name;
    int color;
};

#endif
