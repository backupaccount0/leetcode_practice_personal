/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (55.46%)
 * Likes:    7598
 * Dislikes: 216
 * Total Accepted:    665.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    vector<int> left_nums(nums.rbegin(), nums.rend());
    vector<bool> used(nums.size(), false);
    backtracking(res, path, nums, left_nums, used, 0);
    res.push_back({});
    return res;
  }

 private:
  void backtracking(
      vector<vector<int>>& res,
      vector<int>& path,
      const vector<int>& nums,
      vector<int>& left_nums,
      vector<bool>& used,
      int start_index) {
    if (left_nums.empty()) { return; }
    for (int i = start_index; i < nums.size(); ++i) {
      if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) { continue; }
      path.push_back(nums[i]);
      left_nums.pop_back();
      res.push_back(path);
      used[i] = true;
      backtracking(res, path, nums, left_nums, used, i + 1);
      path.pop_back();
      left_nums.push_back(nums[i]);
      used[i] = false;
    }
  }
};
// @lc code=end
