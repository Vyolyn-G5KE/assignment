#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game.hpp"

int main() {
	std::srand(static_cast<unsigned int>(std::time({})));
    std::int32_t height, width;

    std::cout << "Enter height: ";
    std::cin >> height;
    std::cout << "Enter width: ";
    std::cin >> width;

	game_t game(vec2i_t{ width,height });
	game.run();
	return 0;
}