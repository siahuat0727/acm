/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (35.27%)
 * Total Accepted:    115.9K
 * Total Submissions: 328.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * Empty cells are indicated by the character '.'.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 *
 * Note:
 *
 *
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 *
 *
 */
class Solution {
public:
    bool canFill(const vector<vector<char>>& board, int row, int col, int num) {
        for (int i = 0; i < 9; ++i) {
            // check row
            if (board[row][i] - '0' == num)
                return false;
            // check col
            if (board[i][col] - '0' == num)
                return false;
        }
        // check box
        int rr = row/3 * 3, cc = col/3 * 3;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[rr+i][cc+j] - '0' == num)
                    return false;
        return true;
    }

    bool bt(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        if (col == 9)
            return bt(board, row+1, 0);
        if (board[row][col] != '.')
            return bt(board, row, col+1);

        for (int i = 1; i <= 9; ++i) {
            if (canFill(board, row, col, i)) {
                board[row][col] = i + '0';
                bool ret = bt(board, row, col+1);
                if (ret == true)
                    return true;
            }
        }
        board[row][col] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bt(board, 0, 0);
    }
};
