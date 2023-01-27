/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (66.78%)
 * Likes:    4530
 * Dislikes: 201
 * Total Accepted:    416.7K
 * Total Submissions: 622K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> spiral_matrix(n, vector<int>(n, 0));
    int rot_times = n / 2;
    int num = 1;
    for (int i = 0; i < rot_times; ++i) {
      for (int j = i; j < n - i - 1; ++j) {
        spiral_matrix[i][j] = num;
        num++;
      }
      for (int j = i; j < n - i - 1; ++j) {
        spiral_matrix[j][n - i - 1] = num;
        num++;
      }
      for (int j = n - i - 1; j > i; --j) {
        spiral_matrix[n - i - 1][j] = num;
        num++;
      }
      for (int j = n - i - 1; j > i; --j) {
        spiral_matrix[j][i] = num;
        num++;
      }
    }
    if (n % 2 == 1) { spiral_matrix[n / 2][n / 2] = n * n; }
    return spiral_matrix;
  }
};
// @lc code=end
