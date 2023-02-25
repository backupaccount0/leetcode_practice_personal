/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (63.26%)
 * Likes:    9436
 * Dislikes: 209
 * Total Accepted:    517.4K
 * Total Submissions: 809.8K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> path;
    backtracking(res, path, n);
    return res;
  }

 private:
  void backtracking(vector<vector<string>>& res, vector<int>& path, int n) {
    if (path.size() == n) {
      res.push_back(convertPath(path, n));
      return;
    }
    for (int i = 0; i < n; ++i) {
      int sz = path.size();
      bool flag = false;
      for (int k = 0; k < sz; ++k) {
        if (k - sz == i - path[k] || k - sz == -(i - path[k]) || path[k] == i) {
          flag = true;
          break;
        }
      }
      if (flag) { continue; }
      path.push_back(i);
      backtracking(res, path, n);
      path.pop_back();
    }
  }
  vector<string> convertPath(vector<int>& path, int n) {
    vector<string> s;
    for (auto i : path) {
      string ss(n, '.');
      ss[i] = 'Q';
      s.push_back(ss);
    }
    return s;
  }
};
// @lc code=end
