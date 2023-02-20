/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (67.19%)
 * Likes:    4704
 * Dislikes: 96
 * Total Accepted:    387.3K
 * Total Submissions: 573.8K
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 *
 *
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 *
 *
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations.
 * Using 4 different numbers in the range [1,9], the smallest sum we can get is
 * 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    backtracking(res, path, k, n, 1);
    return res;
  }

 private:
  void backtracking(vector<vector<int>>& res, vector<int>& path, int k, int n, int start_index) {
    if (path.size() == k && sum_ == n) {
      res.push_back(path);
      return;
    }
    if (9 - start_index + 1 < k - path.size()) { return; }
    for (int i = start_index; i <= 9; ++i) {
      if (sum_ + i > n) { return; }
      path.push_back(i);
      sum_ += i;
      backtracking(res, path, k, n, i + 1);
      path.pop_back();
      sum_ -= i;
    }
  }

 private:
  int sum_ = 0;
};
// @lc code=end
