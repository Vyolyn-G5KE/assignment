#include "game.hpp"

#include <iostream>
#include <cstdlib>
 
game_t::game_t(vec2i_t size) : board_(size), scout_(board_) {
    vec2i_t board_pos = {
            (std::rand() % (board_.size().x / 2)) * 2 + 1,
            (std::rand() % (board_.size().y / 2)) * 2 + 1
    };
    board_.generate(board_pos);

    vec2i_t target_pos = {
            (std::rand() % (board_.size().x / 2)) * 2 + 1,
            (std::rand() % (board_.size().y / 2)) * 2 + 1
    };
    board_.set_target(target_pos);

    vec2i_t scout_pos = {
            (std::rand() % (board_.size().x / 2)) * 2 + 1,
            (std::rand() % (board_.size().y / 2)) * 2 + 1
    };
    scout_.set_scout(scout_pos);
}

void game_t::start_game_menu() {
    scout_.get_path().push_back(scout_.get_scout());
    while (true) {
        scout_.print_board();
        std::cout << "\nStart Game Menu:\n";
        std::cout << "1. Up\n";
        std::cout << "1. Down\n";
        std::cout << "1. Left\n";
        std::cout << "1. Right\n";
        std::cout << "2. Backtrack\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";

        char subchoice;
        std::cin >> subchoice;

        switch (subchoice) {
        case 'w':
            scout_.explore({ 0, 1 });
            break;
        case 's':
            scout_.explore({ 0, -1 });
            break;
        case 'a':
            scout_.explore({ -1, 0 });
            break;
        case 'd':
            scout_.explore({ 1, 0 });
            break;
        case '2':
            scout_.backtrack();
            return;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}

void game_t::auto_solve_menu() {
    scout_.solve(scout_.get_scout());
    while (true) {
        scout_.print_board();
        std::cout << "\nAuto-Solve Menu:\n";
        std::cout << "1. View the current path\n";
        std::cout << "2. Quit\n";
        std::cout << "Enter your choice: ";

        char subchoice;
        std::cin >> subchoice;

        switch (subchoice) {
        case '1':
            scout_.print_path();
            break;
        case '2':
            std::cout << "Quitting game.\n";
            return;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}

void game_t::run() {
    while (true) {
        scout_.print_board();
        std::cout << "\nMenu:\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Auto Solve\n";
        std::cout << "3. Quit\n";
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