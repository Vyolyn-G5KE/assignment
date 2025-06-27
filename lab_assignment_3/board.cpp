#include "board.hpp"

#include <cstdlib>

board_t::board_t(vec2i_t size) : size_(size), blocked_(), target_() {
    blocked_ = new bool[size_.y * size_.x];
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

    vec2i_t directions[] = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };

    for (std::size_t i = 3; i > 0; --i) {
        std::size_t j = std::rand() % (i + 1);

        vec2i_t temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

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

void board_t::reset() {
    for (std::int32_t i = 0; i < size_.y * size_.x; ++i) {
        blocked_[i] = true;
    }

    vec2i_t board_pos = {
        (std::rand() % (size_.x / 2)) * 2 + 1,
        (std::rand() % (size_.y / 2)) * 2 + 1
    };
    generate(board_pos);

    vec2i_t target_pos = {
        (std::rand() % (size_.x / 2)) * 2 + 1,
        (std::rand() % (size_.y / 2)) * 2 + 1
    };
    set_target(board_pos);
}