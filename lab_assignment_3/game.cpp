#include "game.hpp"

#include <iostream>
#include <cstdlib>
 
game_t::game_t(vec2i_t size) : board_(size), scout_(board_) {}

void game_t::start_game_menu() {
    board_.reset();
    scout_.reset();
    scout_.set_visited(scout_.get_scout(), true);
    scout_.get_path().push_back(scout_.get_scout());
    system("cls");
    scout_.print_board();

    while (scout_.get_scout() != board_.get_target()) {
        std::cout << "\nStart Game Menu:\n";
        std::cout << "w. Up\n";
        std::cout << "s. Down\n";
        std::cout << "a. Left\n";
        std::cout << "d. Right\n";
        std::cout << "b. Backtrack\n";
        std::cout << "p. Path\n";
        std::cout << "q. Quit\n";
        std::cout << "Enter your choice: ";

        char subchoice;
        std::cin >> subchoice;

        switch (subchoice) {
        case 'w':
            scout_.explore(vec2i_t{ 0, 1 });
            system("cls");
            scout_.print_board();
            break;
        case 's':
            scout_.explore(vec2i_t{ 0, -1 });
            system("cls");
            scout_.print_board();
            break;
        case 'a':
            scout_.explore(vec2i_t{ -1, 0 });
            system("cls");
            scout_.print_board();
            break;
        case 'd':
            scout_.explore(vec2i_t{ 1, 0 });
            system("cls");
            scout_.print_board();
            break;
        case 'b':
            scout_.backtrack();
            system("cls");
            scout_.print_board();
            break;
        case 'p':
            system("cls");
            scout_.print_board();
            scout_.print_path();
            break;
        case 'q':
            system("cls");
            scout_.print_board();
            return;
        default:
            system("cls");
            scout_.print_board();
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
    scout_.print_path();
    std::cout << "You Win!\n";
}

void game_t::auto_solve_menu() {
    board_.reset();
    scout_.reset();
    scout_.solve(scout_.get_scout());
    system("cls");
    scout_.print_board();

    while (scout_.get_scout() != board_.get_target()) {
        std::cout << "\nAuto-Solve Menu:\n";
        std::cout << "1. View the current path\n";
        std::cout << "2. Quit\n";
        std::cout << "Enter your choice: ";

        char subchoice;
        std::cin >> subchoice;

        switch (subchoice) {
        case '1':
            system("cls");
            scout_.print_board();
            scout_.print_path();
            break;
        case '2':
            std::cout << "Quitting game.\n";
            return;
        default:
            system("cls");
            scout_.print_board();
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
    scout_.print_path();
    std::cout << "You Win!\n";
}

void game_t::run() {
    while (true) {
        std::cout << "===========================\n";
        std::cout << "|     MAZE GAME SYSTEM     |\n";
        std::cout << "===========================\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Auto Solve\n";
        std::cout << "3. Quit\n";
        std::cout << "===========================\n";
        std::cout << "Enter your choice: ";

        char choice;
        std::cin >> choice;

        switch (choice) {
        case '1':
            start_game_menu();
            break;
        case '2':
            auto_solve_menu();
            break;
        case '3':
            std::cout << "Quitting game.\n";
            return;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}