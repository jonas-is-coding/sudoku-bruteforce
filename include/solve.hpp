#ifndef SOLVE_HPP
#define SOLVE_HPP

#include "print.hpp"
#include "check.hpp"

bool solve_sudoku(board_t& board, const board_t& original_board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        num_tries++;
                        print_sudoku(board, original_board);
                        if (solve_sudoku(board, original_board)) {
                            return true;
                        }
                        board[row][col] = 0;
                        print_sudoku(board, original_board);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

#endif