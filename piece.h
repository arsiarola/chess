#ifndef PIECE_H
#define PIECE_H

#define WHITE 1
#define BLACK 0

#include <string>

class Piece {
public:
    Piece(std::string = "", int color = 0);
    virtual bool move();
    std::string get_name();
protected:
    std::string name;
    int color;
};

#endif
