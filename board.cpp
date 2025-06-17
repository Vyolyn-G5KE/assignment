#include "board.hpp"

#include <random>

board_t::board_t(std::int32_t rows, std::int32_t cols) : rows_{ rows }, cols_{ cols } {
    blocked_ = new bool* [rows_] {};
    for (std::int32_t i = 0; i < rows_; ++i) {
        blocked_[i] = new bool[cols_] {};
    }
    
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<std::int32_t> distribution(0, 99);

    for (std::int32_t i = 0; i < rows_; ++i) {
        for (std::int32_t j = 0; j < cols_; ++j) {
            if (i == 0 || j == 0 || i == rows_ - 1 || j == cols_ - 1) {
                blocked_[i][j] = true;
            } else {
                blocked_[i][j] = distribution(generator) < 15;
            }
        }
    }
}

board_t::~board_t() {
    for (std::int32_t i = 0; i < rows_; ++i) {
        delete[] blocked_[i];
    }
    delete[] blocked_;
}

bool board_t::blocked(std::int32_t row, std::int32_t col) const { return blocked_[row][col]; }

std::int32_t board_t::rows() const { return rows_; }

std::int32_t board_t::cols() const { return cols_; }