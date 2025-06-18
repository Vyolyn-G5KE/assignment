#include "scout.hpp"

#include "board.hpp"

scout_t::scout_t(const board_t& board) : board_{ board } {
    vec2i_t size = board_.get_size();
    visited_ = new bool* [size.y] {};
    for (std::int32_t i = 0; i < size.y; ++i) {
        visited_[i] = new bool[size.x] {};
    }
}

scout_t::~scout_t() {
    vec2i_t size = board_.get_size();
    for (std::int32_t i = 0; i < size.y; ++i) {
        delete[] visited_[i];
    }
    delete[] visited_;
}

const vec2i_t& scout_t::get_position() const {
    return position_;
}

void scout_t::set_position(const vec2i_t& pos) {
    position_ = pos;
}

bool scout_t::get_visited(const vec2i_t& pos) const {
    return visited_[pos.y][pos.x];
}

void scout_t::set_visited(const vec2i_t& pos, bool value) {
    visited_[pos.y][pos.x] = value;
}
