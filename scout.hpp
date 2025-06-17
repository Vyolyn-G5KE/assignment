#ifndef SCOUT_HPP
#define SCOUT_HPP

#include <iostream>
#include <cstdint>

#include "math.hpp"
#include "list.hpp"

class scout_t {
public:
    scout_t(std::int32_t rows, std::int32_t cols);
    ~scout_t();

    bool visited(std::int32_t row, std::int32_t col) const;
    void move(const vec2i_t& delta);

private:
    vec2i_t position_{};
    list_t<vec2i_t> path_{};
    bool** visited_{};
    std::int32_t rows_{};
    std::int32_t cols_{};
};

#endif  // SCOUT_HPP