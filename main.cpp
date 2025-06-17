#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game.hpp"

int main() {
	std::srand(static_cast<unsigned int>(std::time({})));
	return 0;
}