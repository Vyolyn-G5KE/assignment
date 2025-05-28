#include "board.hpp"

board::board(int r, int c) : rows(r), cols(c) {
    blocked = new bool* [rows];
    for (int i = 0; i < rows; ++i) {
        blocked[i] = new bool[cols]();
    }
}

board::~board() {
    for (int i = 0; i < rows; ++i) {
        delete[] blocked[i];
    }
    delete[] blocked;
}