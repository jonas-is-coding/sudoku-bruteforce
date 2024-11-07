#ifndef CHECK_HPP
#define CHECK_HPP

bool is_valid(const board_t& board, int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == num) {
            return false;
        }
    }
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = start_row; i < start_row + 3; ++i) {
        for (int j = start_col; j < start_col + 3; ++j) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

#endif