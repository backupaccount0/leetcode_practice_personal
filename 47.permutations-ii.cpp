/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (56.88%)
 * Likes:    7131
 * Dislikes: 127
 * Total Accepted:    760.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(res, path, nums, used);
    return res;
  }

 private:
  void backtracking(vector<vector<int>>& res, vector<int>& path, const vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) { continue; }
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

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtracking(res, path, nums, 0);
    return res;
  }

 private:
  void backtracking(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int start_index) {
    if (path.size() >= 2) { res.push_back(path); }
    vector<bool> used(201, false);
    for (int i = start_index; i < nums.size(); ++i) {
      if (!path.empty() && nums[i] < path.back() || used[nums[i] + 100]) { continue; }
      path.push_back(nums[i]);
      used[nums[i] + 100] = true;
      backtracking(res, path, nums, i + 1);
      path.pop_back();
    //   used[nums[i] + 100] = false;
    }
  }
};
