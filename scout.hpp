#ifndef SCOUT_HPP
#define SCOUT_HPP

#include "list.hpp"
#include "board.hpp"

class board;

struct position {
    int x;
    int y;

    position() : x(0), y(0) {}
    position(int x, int y) : x(x), y(y) {}
};

class scout {
private:
    const board& b;
    list<position> path;
    bool** visited;
    int rows;
    int cols;

public:
    scout(const board& b, position begin, int r, int c);
    ~scout();
};

#endif // SCOUT_HPP