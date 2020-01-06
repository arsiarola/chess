#include "rook.h"
#include "../tile.h"
#include "../tools.h"
#include "../board.h"

#include <iostream>
#include <string>

using std::cout;

Rook::Rook(Color color_) {
    color = color_;
    name = "R";
}

void Rook::move(Tile &from, Tile &destination, Board &board) {
    int x_diff = get_x_diff(from, destination);
    int y_diff = get_y_diff(from, destination); // - move up and + move down
    int from_tile = from.get_tile_num();
    int dest_tile = destination.get_tile_num();

}    
    

			
