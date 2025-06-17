#include "board.hpp"

board_t::board_t(const vec2i_t& size) : size_{ size } {
    blocked_ = new bool* [size_.x] {};
    for (std::int32_t i = 0; i < size_.x; ++i) {
        blocked_[i] = new bool[size_.y] {};
    }
}

board_t::~board_t() {
    for (std::int32_t i = 0; i < size_.x; ++i) {
        delete[] blocked_[i];
    }
    delete[] blocked_;
}

bool board_t::get_blocked(const vec2i_t& pos) const {
    return blocked_[pos.x][pos.y];
}

void board_t::set_blocked(const vec2i_t& pos, bool value) {
    blocked_[pos.x][pos.y] = value;
}