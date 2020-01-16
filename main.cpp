#include "main.h"
#include "tools.h"
#include "board.h"
#include <iostream>

using std::cout;

int main() {
    
    Board board;
    int option = 0;
    bool correct = false;
    print_options();
    while (!correct) {
	while (!(std::cin >> option)) {
	    cout << "the input has to be a number!\n";
	}

	switch (option) {
	case PLAY:
	    correct = true;
	    while (!board.is_game_over()) {
		board.players_turn();
	    }
	    break;

	case QUIT:
	    correct = true;
	    return 0;
   
	default:
	    cout << "Incorrect value, please enter one of the options below\n";
	    print_options();
	    std::cin.clear();
	    std::cin.ignore(256, '\n');
	    break; 
	}
    }
    cout << "Game ended winner is " << board.get_winner_string() << "\n";
    return 0;
}

void print_options() {
    cout << "Enter one of the options below\n"
	 << PLAY << ". Start new game\n"
	 << QUIT << ". Quit\n";
}
