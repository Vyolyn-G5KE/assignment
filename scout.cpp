#include "scout.hpp"

#include "board.hpp"

scout_t::scout_t(std::int32_t rows, std::int32_t cols) : rows_{ rows }, cols_{ cols } {
    // path_.push_back(begin);
    visited_ = new bool* [rows_] {};
    for (std::int32_t i = 0; i < rows_; ++i) {
        visited_[i] = new bool[cols_] {};
    }
}

scout_t::~scout_t() {
    for (std::int32_t i = 0; i < rows_; ++i) {
        delete[] visited_[i];
    }
    delete[] visited_;
}

bool scout_t::visited(std::int32_t row, std::int32_t col) const { return visited_[row][col]; }

void scout_t::move(const vec2i_t& position) {
    position_ = position;
    path_.push_back(position_);
}