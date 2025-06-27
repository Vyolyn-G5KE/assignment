#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::int32_t height = 0, width = 0;

    while (true) {
        std::cout << "Enter height (odd and >= 5): ";
        std::cin >> height;

        if (std::cin && height >= 5 && height % 2 == 1)
            break;

        std::cout << "Invalid input. Height must be an odd number >= 5.\n";

        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    while (true) {
        std::cout << "Enter width (odd and >= 5): ";
        std::cin >> width;

        if (std::cin && width >= 5 && width % 2 == 1)
            break;

        std::cout << "Invalid input. Width must be an odd number >= 5.\n";

        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    game_t game(vec2i_t{ width, height });
    game.run();

    return 0;
}