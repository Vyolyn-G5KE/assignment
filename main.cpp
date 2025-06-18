#include <iostream>

#include "game.hpp"

int main() {
	std::int32_t num{};
	std::cin >> num;
	game_t game({ num,num });
	game.print();
	return 0;
}