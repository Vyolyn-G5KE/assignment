#include "scout.hpp"

#include <iostream>
#include "board.hpp"

scout_t::scout_t(const board_t& board) : board_(board), visited_(), scout_(), path_() {
    visited_ = new bool[board_.size().y * board_.size().x];
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

list_t<vec2i_t>& scout_t::get_path() {
    return path_;
}

bool scout_t::explore(vec2i_t w) {
    if (get_visited(get_scout() + w) || board_.get_blocked(get_scout() + w))
        return false;
    set_visited(get_scout() + w, true);
    path_.push_back(get_scout() + w);
    set_scout(get_scout() + w);
    return true;
}

bool scout_t::backtrack() {
    if (path_.empty())
        return false;
    vec2i_t directions[] = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };
    for (const vec2i_t& dir : directions) {
        if (get_visited(get_scout() + dir) || board_.get_blocked(get_scout() + dir))
            continue;
        return false;
    }
    path_.pop_back();
    set_scout(path_.back());
    return true;
}

bool scout_t::solve(vec2i_t v) {
    set_visited(v, true);
    path_.push_back(v);
    set_scout(v);
    if (v == board_.get_target())
        return true;
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
    set_scout(path_.back());
    return false;
}

void scout_t::reset() {
    for (std::int32_t i = 0; i < board_.size().y * board_.size().x; ++i) {
        visited_[i] = false;
    }

    path_.clear();

    vec2i_t scout_pos = {
        (std::rand() % (board_.size().x / 2)) * 2 + 1,
        (std::rand() % (board_.size().y / 2)) * 2 + 1
    };
    set_scout(scout_pos);
}

void scout_t::print_board(bool solve) {
    vec2i_t size = board_.size();

    for (std::int32_t y = size.y - 1; y >= 0; --y) {
        for (std::int32_t x = 0; x < size.x; ++x) {
            vec2i_t pos = { x, y };

            bool is_path = false;
            for (const vec2i_t& p : path_) {
                if (p.x == pos.x && p.y == pos.y) {
                    is_path = true;
                    break;
                }
            }

            if ((solve && path_.front() == pos) || (!solve && scout_ == pos)) {
                std::cout << "\x1b[93mS \x1b[0m";
            }
            else if (board_.get_target() == pos) {
                std::cout << "\x1b[92mT \x1b[0m";
            }
            else if (is_path) {
                std::cout << "\x1b[94m* \x1b[0m";
            }
            else if (board_.get_blocked(pos)) {
                std::cout << "\x1b[91mX \x1b[0m";
            }
            else if (visited_[pos.y * board_.size().x + pos.x]) {
                std::cout << "\x1b[95m- \x1b[0m";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

void scout_t::print_path() {
    std::cout << "Path: [";
    bool first = true;
    for (const vec2i_t& p : path_) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << "(" << p.x << "," << p.y << ")";
        first = false;
    }
    std::cout << "]\n";
}