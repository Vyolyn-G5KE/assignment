#ifndef GAME_HPP
#define GAME_HPP

#include <random>

#include "board.hpp"
#include "scout.hpp"

class game_t {
public:
	game_t(const vec2i_t& size);
	void dfs(const vec2i_t& pos);

    void print() {
        for (std::int32_t i = 0; i < board_.get_size().x; ++i) {
            for (std::int32_t j = 0; j < board_.get_size().y; ++j) {
                if (board_.get_blocked({ i,j })) {
                    std::cout << "X ";
                }
                else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
    }

private:
    board_t board_;
    scout_t scout_;
    vec2i_t target_;
};

#endif // GAME_HPP