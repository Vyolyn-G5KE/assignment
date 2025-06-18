#ifndef SCOUT_HPP
#define SCOUT_HPP

#include "math.hpp"
#include "list.hpp"

class board_t;

class scout_t {
public:
    scout_t(const board_t& board);
    ~scout_t();

    const vec2i_t& get_position() const;
    void set_position(const vec2i_t& pos);
    bool get_visited(const vec2i_t& pos) const;
    void set_visited(const vec2i_t& pos, bool value);

private:
    const board_t& board_;
    bool** visited_{};
    vec2i_t position_{};
    list_t<vec2i_t> path_{};
};

#endif  // SCOUT_HPP