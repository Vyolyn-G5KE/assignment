#include "scout.hpp"

scout::scout(const board& b, position begin, int r, int c) : b(b), rows(r), cols(c) {
    path.push_back(begin);
    visited = new bool* [rows];
    for (int i = 0; i < rows; ++i) {
        visited[i] = new bool[cols]();
    }
}

scout::~scout() {
    for (int i = 0; i < rows; ++i) {
        delete[] visited[i];
    }
    delete[] visited;
}
