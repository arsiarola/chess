#include "board.h"
#include <iostream>

using std::cout;

int main() {
        Board board;
    while (true) {
        int option = 0;
        cout << "Enter one of the options below\n"
            "1. Start new game\n"
            "2. Load existing game\n"
            "3. Quit\n";

        std::cin >> option;
        cout << option;

        switch (option) {
        case PLAY:
            while (!board.is_game_over()) {
                board.players_turn();
            }

        case LOAD:
            // TODO

        case QUIT:
            return 0;
        }
    }

    cout << "Game ended winner is " << board.get_winner_string() << "\n";
    return 0;
}
