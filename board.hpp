#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#include "math.hpp"

class board_t {
public:
    board_t(const vec2i_t& size);
    ~board_t();

    const vec2i_t& get_size() const;
    bool get_blocked(const vec2i_t& pos) const;
    void set_blocked(const vec2i_t& pos, bool value);

private:
    vec2i_t size_{};
    bool** blocked_{};
};

#endif  // BOARD_HPP