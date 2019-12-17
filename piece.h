#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
public:
    Piece(std::string = "hello", int x = 0, int y = 0, int color = 0);
    virtual bool move() {};
    std::string get_name();
    int get_x();
    int get_y();
protected:
    std::string name;
    int x;
    int y;
    int color;
};

#endif
