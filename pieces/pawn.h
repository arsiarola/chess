#ifndef PAWN_H
#define PAWN_H

#include "../piece.h"

class Tile;
class Board;

#define UP -1
#define DOWN 1

class Pawn : public Piece {
public:
    virtual void move(Tile &from ,Tile &destination, Board &board);
    Pawn(Color color_);
    
private:
    bool can_black_eat(Tile &from, Tile &destination, Board &board);
    bool can_white_eat(Tile &from, Tile &destination, Board &board);
    bool is_piece_in_front (Tile &from, Tile &destination, Board &board);
    bool is_correct_direction(Tile &from, Tile &destination);
    void move_pawn_on_board(Tile &from, Tile &destination);

    using Piece::move;
    bool first_move = true;
};


#endif

