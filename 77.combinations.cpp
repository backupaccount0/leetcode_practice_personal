/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (66.32%)
 * Likes:    5705
 * Dislikes: 176
 * Total Accepted:    640K
 * Total Submissions: 959.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    backtracking(res, path, n, k, 1);
    return res;
  }
  void backtracking(vector<vector<int>>& res, vector<int>& path, int n, int k, int start) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }
    for (int i = start; i <= n - k + path.size()+1; ++i) {
      path.push_back(i);
      backtracking(res, path, n, k, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
