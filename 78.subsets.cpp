/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (74.12%)
 * Likes:    13654
 * Dislikes: 191
 * Total Accepted:    1.4M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtracking(res, path, nums, 0);
    res.push_back({});
    return res;
  }

 private:
  void backtracking(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int start_index) {
    for (int i = start_index; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      res.push_back(path);
      backtracking(res, path, nums, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
