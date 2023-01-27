/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (65.53%)
 * Likes:    1641
 * Dislikes: 942
 * Total Accepted:    130.7K
 * Total Submissions: 199.2K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 *
 * You are given an m x n char matrix board representing the game board
 * where:
 *
 *
 * 'M' represents an unrevealed mine,
 * 'E' represents an unrevealed empty square,
 * 'B' represents a revealed blank square that has no adjacent mines (i.e.,
 * above, below, left, right, and all 4 diagonals),
 * digit ('1' to '8') represents how many mines are adjacent to this revealed
 * square, and
 * 'X' represents a revealed mine.
 *
 *
 * You are also given an integer array click where click = [clickr, clickc]
 * represents the next click position among all the unrevealed squares ('M' or
 * 'E').
 *
 * Return the board after revealing this position according to the following
 * rules:
 *
 *
 * If a mine 'M' is revealed, then the game is over. You should change it to
 * 'X'.
 * If an empty square 'E' with no adjacent mines is revealed, then change it to
 * a revealed blank 'B' and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square 'E' with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]],
 * click = [3,0]
 * Output:
 * [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 *
 *
 * Example 2:
 *
 *
 * Input: board =
 * [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]],
 * click = [1,2]
 * Output:
 * [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 50
 * board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
 * click.length == 2
 * 0 <= clickr < m
 * 0 <= clickc < n
 * board[clickr][clickc] is either 'M' or 'E'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] == "M") { board[click[0]][click[1]] = "X" return board; }
  }
  int width = board[0].size();
  int height = board.size();
  vector<vector<int>> empty_square_to_reveal{click};
  while (!empty_square_to_reveal.empty()) {
    for (auto spot : empty_square_to_reveal) {
      bool boom_occr = false;
      for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
          int row = spot[0] + i;
          int col = spot[1] + j;
          if (row >= 0 && col >= 0 && row < height && col < width) {
            if (board[row][col] == "E") {
              empty_square_to_reveal.push_back(vector<int>{row, col});
            } else if (board[row][col] == "E")
          }
        }
      }
    }
  }
};
// @lc code=end
