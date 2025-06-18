#include "board.hpp"

board_t::board_t(const vec2i_t& size) : size_{ size } {
    blocked_ = new bool* [size_.y] {};
    for (std::int32_t i = 0; i < size_.y; ++i) {
        blocked_[i] = new bool[size_.x] {};
    }
}

board_t::~board_t() {
    for (std::int32_t i = 0; i < size_.y; ++i) {
        delete[] blocked_[i];
    }
    delete[] blocked_;
}

const vec2i_t& board_t::get_size() const {
    return size_;
}

bool board_t::get_blocked(const vec2i_t& pos) const {
    return blocked_[pos.y][pos.x];
}

void board_t::set_blocked(const vec2i_t& pos, bool value) {
    blocked_[pos.y][pos.x] = value;
}