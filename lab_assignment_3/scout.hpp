#ifndef SCOUT_HPP
#define SCOUT_HPP

#include "math.hpp"
#include "list.hpp"

class board_t;

class scout_t {
public:
    scout_t(const board_t& board);
    ~scout_t();

    bool get_visited(vec2i_t pos) const;
    void set_visited(vec2i_t pos, bool value);
    vec2i_t get_scout();
    void set_scout(vec2i_t pos);
    bool explore(vec2i_t w);
    bool backtrack();
    bool solve(vec2i_t v);
    void print_board();
    void print_path();

private:
    const board_t& board_;
    bool* visited_;
    vec2i_t scout_;
    list_t<vec2i_t> path_;
};

#endif  // SCOUT_HPP