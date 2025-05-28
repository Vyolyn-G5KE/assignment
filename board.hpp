#ifndef BOARD_HPP
#define BOARD_HPP

class board {
private:
    bool** blocked;
    int rows;
    int cols;

public:
    board(int r, int c);
    ~board();
};

#endif // BOARD_HPP