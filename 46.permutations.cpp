/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.97%)
 * Likes:    14758
 * Dislikes: 251
 * Total Accepted:    1.5M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtracking(res, path, nums, used);
    return res;
  }
  void backtracking(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) { res.push_back(path); }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) { continue; }
      path.push_back(nums[i]);
      used[i] = true;
      backtracking(res, path, nums, used);
      path.pop_back();
      used[i] = false;
    }
  }
};
// @lc code=end
