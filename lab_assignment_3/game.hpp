#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "scout.hpp"

class game_t {
public:
	game_t(vec2i_t size);

    void start_game_menu();
    void auto_solve_menu();
    void run();

private:
    board_t board_;
    scout_t scout_;
};

#endif // GAME_HPP