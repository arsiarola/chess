#include "main.h"
#include "tools.h"
#include "board.h"
#include <iostream>

using std::cout;

int main() {
    
    Board board;
    int option = 0;
    print_options();
    while (!(std::cin >> option)) {
	cout << "Incorrect value, please enter one of the options below\n";
	print_options();
	std::cin.clear();
	std::cin.ignore(256, '\n');

    }

    switch (option) {
    case PLAY:
	while (!board.is_game_over()) {
	    board.players_turn();
	}

    case QUIT:
	return 0;
    }

    cout << "Game ended winner is " << board.get_winner_string() << "\n";
    return 0;
}


void print_options() {
    cout << "Enter one of the options below\n"
	 << PLAY << ". Start new game\n"
	 << QUIT << ". Quit\n";
    

}
