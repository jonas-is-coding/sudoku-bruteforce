#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <vector>

int num_tries = 0;

const std::string BLUE = "\033[96m";
const std::string GREEN = "\033[92m";
const std::string WHITE = "\033[37m";
const std::string RESET = "\033[0m";

typedef std::vector<int> row_t, col_t;
using board_t = std::vector<row_t>;

board_t board = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

#endif