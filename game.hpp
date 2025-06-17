#ifndef GAME_HPP
#define GAME_HPP

#include <random>

#include "board.hpp"
#include "scout.hpp"

class game_t {
public:
	game_t(const vec2i_t& size);
	
private:
	board_t board_;
	scout_t scout_;
	vec2i_t target_;
};

#endif // GAME_HPP