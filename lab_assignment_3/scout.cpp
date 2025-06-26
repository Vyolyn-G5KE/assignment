#include "scout.hpp"

#include <iostream>
#include <vector>
#include "board.hpp"

scout_t::scout_t(const board_t& board) : board_(board), visited_(), scout_(), path_() {
    visited_ = new bool[board_.size().y * board_.size().x]();
}

scout_t::~scout_t() {
    delete[] visited_;
}

bool scout_t::get_visited(vec2i_t pos) const {
    return visited_[pos.y * board_.size().x + pos.x];
}

void scout_t::set_visited(vec2i_t pos, bool value) {
    visited_[pos.y * board_.size().x + pos.x] = value;
}

vec2i_t scout_t::get_scout() {
    return scout_;
}

void scout_t::set_scout(vec2i_t pos) {
    scout_ = pos;
}

bool scout_t::explore(vec2i_t w) {
    if (board_.get_blocked(w))
        return false;
    path_.push_back(w);
    return true;
}

bool scout_t::backtrack() {
    if (path_.empty())
        return false;
    path_.pop_back();
    return true;
}

bool scout_t::solve(vec2i_t v) {
    if (v == board_.get_target())
        return true;
    set_visited(v, true);
    path_.push_back(v);
    vec2i_t directions[] = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };
    for (const vec2i_t& dir : directions) {
        vec2i_t w = v + dir;

        if (get_visited(w) || board_.get_blocked(w))
            continue;

        if (solve(w))
            return true;
    }
    path_.pop_back();
    return false;
}

void scout_t::print_board() {
    vec2i_t size = board_.size();

    bool** path = new bool* [size.y];
    for (int y = 0; y < size.y; ++y) {
        path[y] = new bool[size.x] {};
    }

    for (const vec2i_t& pos : path_) {
        path[pos.y][pos.x] = true;
    }

    for (std::int32_t y = 0; y < size.y; ++y) {
        for (std::int32_t x = 0; x < size.x; ++x) {
            vec2i_t pos = { x, y };

            if (board_.get_target() == pos) {
                std::cout << "\x1b[92mT \x1b[0m";
            }
            else if (scout_ == pos) {
                std::cout << "\x1b[93mS \x1b[0m";
            }
            else if (path[pos.y][pos.x]) {
                std::cout << "* ";
            }
            else if (board_.get_blocked(pos)) {
                std::cout << "X ";
            }
            else if (visited_[pos.y * board_.size().x + pos.x]) {
                std::cout << "0 ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }

    for (int y = 0; y < size.y; ++y) {
        delete[] path[y];
    }
    delete[] path;
}

void scout_t::print_path() {
    for (const vec2i_t& path : path_) {
        std::cout << "(" << path.x << "," << path.y << "), ";
    }
    std::cout << '\n';
}