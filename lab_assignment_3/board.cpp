#include "board.hpp"

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>

board_t::board_t(vec2i_t size) : size_(size), blocked_(), target_() {
    blocked_ = new bool[size_.y * size_.x];
    for (std::int32_t i = 0; i < size_.y * size_.x; ++i) {
        blocked_[i] = true;
    }
}

board_t::~board_t() {
    delete[] blocked_;
}

vec2i_t board_t::size() const {
    return size_;
}

bool board_t::get_blocked(vec2i_t pos) const {
    return blocked_[pos.y * size_.x + pos.x];
}

void board_t::set_blocked(vec2i_t pos, bool value) {
    blocked_[pos.y * size_.x + pos.x] = value;
}

vec2i_t board_t::get_target() const {
    return target_;
}

void board_t::set_target(vec2i_t pos) {
    target_ = pos;
}

void board_t::generate(vec2i_t v) {
    set_blocked(v, false);

    std::vector<vec2i_t> directions = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };

    std::shuffle(directions.begin(), directions.end(), std::default_random_engine(std::rand()));

    for (const vec2i_t& dir : directions) {
        vec2i_t w = { v.x + dir.x * 2, v.y + dir.y * 2 };

        if (w.y < 0 || w.y >= size_.y || w.x < 0 || w.x >= size_.x)
            continue;

        if (!get_blocked(w))
            continue;

        set_blocked(v + dir, false);
        generate(w);
    }
}
