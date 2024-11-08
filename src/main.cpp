#include <iostream>
#include <chrono>

#include "../include/print.hpp"
#include "../include/solve.hpp"

int main() {
    board_t original_board = board;
    print_sudoku(board, original_board);

    auto start = std::chrono::high_resolution_clock::now();

    if (solve_sudoku(board, original_board)) {
        auto end = std::chrono::high_resolution_clock::now();
        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(end - start).count();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        std::cout << "Sudoku solved!" << std::endl;
        std::cout << "Number of tries: " << num_tries << std::endl;
        std::cout << "Time taken: " << minutes << " minutes and " << seconds << "," << milliseconds << " seconds" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}