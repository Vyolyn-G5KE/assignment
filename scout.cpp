#include "scout.hpp"

scout_t::scout_t(const vec2i_t& size) : size_{ size } {
    visited_ = new bool* [size_.x] {};
    for (std::int32_t i = 0; i < size_.x; ++i) {
        visited_[i] = new bool[size_.y] {};
    }
}

scout_t::~scout_t() {
    for (std::int32_t i = 0; i < size_.x; ++i) {
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
    return visited_[pos.x][pos.y];
}

void scout_t::set_visited(const vec2i_t& pos, bool value) {
    visited_[pos.x][pos.y] = value;
}
