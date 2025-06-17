#ifndef SCOUT_HPP
#define SCOUT_HPP

#include <iostream>
#include <cstdint>

#include "list.hpp"

class board_t;

struct position_t {
    std::int32_t x{};
    std::int32_t y{};

    position_t();
    position_t(std::int32_t x, std::int32_t y);
};

class scout_t {
public:
    scout_t(board_t& board, const position_t& begin);
    ~scout_t();

    bool visited(std::int32_t row, std::int32_t col) const;
    void move(const position_t& dest);

    void print() const;

private:
    board_t& board_;
    list_t<position_t> path_{};
    bool** visited_{};
    std::int32_t rows_{};
    std::int32_t cols_{};
};

#endif  // SCOUT_HPP