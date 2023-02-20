// @before-stub-for-debug-begin
#include <algorithm>
#include <string>
#include <vector>
#include "commoncppproblem40.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (53.35%)
 * Likes:    7926
 * Dislikes: 200
 * Total Accepted:    708.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    backtracking(res, path, candidates, target, 0, used);
    return res;
  }

 private:
  void backtracking(
      vector<vector<int>>& res,
      vector<int>& path,
      vector<int>& candidates,
      int target,
      int start_index,
      vector<bool>& used) {
    if (sum_ == target) {
      res.push_back(path);
      return;
    }
    for (int i = start_index; i < candidates.size(); ++i) {
      if (sum_ + candidates[i] > target) { return; }
      if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) { continue; }
      path.push_back(candidates[i]);
      sum_ += candidates[i];
      used[i] = true;
      backtracking(res, path, candidates, target, i + 1, used);
      path.pop_back();
      sum_ -= candidates[i];
      used[i] = false;
    }
  }

 private:
  int sum_ = 0;
};
// @lc code=end
