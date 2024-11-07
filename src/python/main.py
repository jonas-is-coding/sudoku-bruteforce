import os
import time
from typing import List

Board = List[List[int]]

# Color constants
BLUE = "\033[96m"
GREEN = "\033[92m"
WHITE = "\033[37m"
RESET = "\033[0m"

num_tries = 0

board = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

def print_sudoku(board: Board, original_board: Board) -> None:
    os.system('cls' if os.name == 'nt' else 'clear')
    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] != 0 and original_board[row][col] != 0:
                print(f"{BLUE}{board[row][col]} {RESET}", end="")
            elif board[row][col] != 0:
                print(f"{GREEN}{board[row][col]} {RESET}", end="")
            else:
                print(f"{WHITE}. {RESET}", end="")
        print()
    print()

def is_valid(board: Board, row: int, col: int, num: int) -> bool:
    for i in range(9):
        if board[row][i] == num:
            return False
        
    for i in range(9):
        if board[i][col] == num:
            return False
    
    start_row = (row // 3) * 3
    start_col = (col // 3) * 3
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if board[i][j] == num:
                return False
    
    return True

def solve_sudoku(board: Board, original_board: Board) -> bool:
    global num_tries
    
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        num_tries += 1
                        print_sudoku(board, original_board)
                        
                        if solve_sudoku(board, original_board):
                            return True
                        
                        board[row][col] = 0
                        print_sudoku(board, original_board)
                return False
    return True

def main():
    original_board = [row[:] for row in board]
    print_sudoku(board, original_board)
    
    start_time = time.time()
    
    if solve_sudoku(board, original_board):
        end_time = time.time()
        elapsed_time = end_time - start_time
        
        minutes = int(elapsed_time // 60)
        seconds = int(elapsed_time % 60)
        milliseconds = int((elapsed_time * 1000) % 1000)
        
        print("Sudoku gelöst!")
        print(f"Anzahl der Versuche: {num_tries}")
        print(f"Benötigte Zeit: {minutes} Minuten und {seconds},{milliseconds:03d} Sekunden")
    else:
        print("Keine Lösung gefunden.")

if __name__ == "__main__":
    main()