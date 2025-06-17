#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>

class board_t {
public:
    board_t(std::int32_t rows, std::int32_t cols);
    ~board_t();

    bool blocked(std::int32_t row, std::int32_t col) const;
    std::int32_t rows() const;
    std::int32_t cols() const;

private:
    bool** blocked_{};
    std::int32_t rows_{};
    std::int32_t cols_{};
};

#endif  // BOARD_HPP