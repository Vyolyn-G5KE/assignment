#ifndef BOARD_HPP
#define BOARD_HPP

#include "math.hpp"

class board_t {
public:
    board_t(const vec2i_t& size);
    ~board_t();

    bool get_blocked(const vec2i_t& pos) const;
    void set_blocked(const vec2i_t& pos, bool value);

private:
    bool** blocked_{};
    vec2i_t size_{};
};

#endif  // BOARD_HPP