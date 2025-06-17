#ifndef GAME_HPP
#define GAME_HPP

#include <cstdint>

#include "board.hpp"
#include "scout.hpp"

class game_t {
public:
	game_t(std::int32_t rows, std::int32_t cols);
private:
	board_t board_;
	scout_t scout_;
};

#endif // GAME_HPP