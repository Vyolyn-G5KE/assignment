#include "scout.hpp"

#include "board.hpp"

position_t::position_t() {}

position_t::position_t(std::int32_t x, std::int32_t y) : x{ x }, y{ y } {}

scout_t::scout_t(board_t& board, const position_t& begin) : board_{ board }, rows_{ board.rows() }, cols_{ board.cols() } {
    path_.push_back(begin);
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

void scout_t::move(const position_t& dest) {
    position_t current = path_.back();
    if (!visited(dest.x, dest.y) && !board_.blocked(dest.x, dest.y)) {
        path_.push_back(position_t(current.x + dest.x, current.y + dest.y));
        visited_[current.x + dest.x][current.y + dest.y] = true;
    }
}

void scout_t::print() const {
    for (std::int32_t i = 0; i < rows_; ++i) {
        for (std::int32_t j = 0; j < cols_; ++j) {
            if (board_.blocked(i, j)) {
                std::cout << "X ";
            }
            else if (visited(i, j)) {
                std::cout << "O ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}