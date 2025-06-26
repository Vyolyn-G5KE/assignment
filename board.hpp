#ifndef BOARD_HPP
#define BOARD_HPP

#include "math.hpp"

class board_t {
public:
    board_t(vec2i_t size);
    ~board_t();

    vec2i_t size() const;
    bool get_blocked(vec2i_t pos) const;
    void set_blocked(vec2i_t pos, bool value);
    vec2i_t get_target() const;
    void set_target(vec2i_t pos);
    void generate(vec2i_t v);

private:
    vec2i_t size_;
    bool* blocked_;
    vec2i_t target_;
};

#endif  // BOARD_HPP