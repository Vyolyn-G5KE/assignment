#include "board.hpp"

#include <random>

board_t::board_t(std::int32_t rows, std::int32_t cols) : rows_{ rows }, cols_{ cols } {
    blocked_ = new bool* [rows_] {};
    for (std::int32_t i = 0; i < rows_; ++i) {
        blocked_[i] = new bool[cols_] {};
    }
}

board_t::~board_t() {
    for (std::int32_t i = 0; i < rows_; ++i) {
        delete[] blocked_[i];
    }
    delete[] blocked_;
}

bool board_t::blocked(std::int32_t row, std::int32_t col) const { return blocked_[row][col]; }