#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include "types.hpp"

void print_sudoku(const board_t& board, const board_t& original_board) {
    system("clear");
    for (size_t row = 0; row < board.size(); ++row) {
        for (size_t col = 0; col < board[row].size(); ++col) {
            if (board[row][col] != 0 && original_board[row][col] != 0) {
                std::cout << BLUE << board[row][col] << " " << RESET;
            } else if (board[row][col] != 0) {
                std::cout << GREEN << board[row][col] << " " << RESET;
            } else {
                std::cout << WHITE << ". " << RESET;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif