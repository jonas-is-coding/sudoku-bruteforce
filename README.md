# Sudoku Brute Forcer

This project implements a Sudoku solver via brute forcing in C++. The solver can solve any given Sudoku puzzle, with varying difficulty levels.

## Requirements

- C++11 or later
- A C++ compiler (e.g., `g++`)

## Installation

1. Clone this repository:
```bash
   git clone https://github.com/your-username/sudoku-solver.git
```
2.	Navigate to the project directory:
```bash
cd sudoku-solver
```
3.	Compile the project using g++:
```bash
g++ -std=c++11 -O2 main.cpp -o sudoku-solver
```
4.	Run the executable:
```bash
./sudoku-solver
```

## Usage

1.	Generating a Sudoku Puzzle: The program generates a new Sudoku puzzle based on the specified fill percentage, where a higher percentage means an easier puzzle.
2.	Solving a Sudoku Puzzle: If a Sudoku puzzle is provided as input, the program will solve it using a backtracking algorithm.

## File Structure

- main.cpp: Main entry point of the application.
- solve.hpp and solve.cpp: Contains the logic for solving the Sudoku puzzle.
- generate.hpp and generate.cpp: Contains the logic for generating Sudoku puzzles.
- check.hpp: Contains the validation functions for checking whether a Sudoku puzzle is valid.
- types.hpp: Defines the board structure (board_t), a 9x9 matrix representing the Sudoku grid.