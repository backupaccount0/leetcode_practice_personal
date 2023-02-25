// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (56.96%)
 * Likes:    7410
 * Dislikes: 198
 * Total Accepted:    438.8K
 * Total Submissions: 764K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

// @lc code=start

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { backtracking(board); }

 private:
  bool backtracking(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '.') {
          for (int val = 1; val <= 9; ++val) {
            if (isVaild(board, val, i, j)) {
              board[i][j] = '0' + val;
              if (backtracking(board)) { return true; }
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  bool isVaild(const vector<vector<char>>& board, const int val, const int x, const int y) {
    for (int i = 0; i < board.size(); ++i) {
      if (i != x && board[i][y] == val + '0') { return false; }
    }
    for (int j = 0; j < board[0].size(); ++j) {
      if (j != y && board[x][j] == val + '0') { return false; }
    }
    for (int m = x / 3 * 3; m < x / 3 * 3 + 3; ++m) {
      for (int n = y / 3 * 3; n < y / 3 * 3 + 3; ++n) {
        if (m != x && n != y && board[m][n] == val + '0') { return false; }
      }
    }
    return true;
  }
};
// @lc code=end
