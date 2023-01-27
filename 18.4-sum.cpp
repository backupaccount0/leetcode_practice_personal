// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.14%)
 * Likes:    8533
 * Dislikes: 990
 * Total Accepted:    698.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
#include <algorithm>
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) { return {}; }
    sort(nums.begin(), nums.end());
    if (nums[0] > target && target >= 0) { return {}; }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) { continue; }
      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) { continue; }
        int lp = j + 1;
        int rp = nums.size() - 1;
        while (lp < rp) {
          if ((long)nums[i] + (long)nums[j] + (long)nums[lp] + (long)nums[rp] > target) {
            rp--;
          } else if ((long)nums[i] + (long)nums[j] + (long)nums[lp] + (long)nums[rp] < target) {
            lp++;
          } else {
            res.emplace_back(vector<int>{nums[i], nums[j], nums[lp], nums[rp]});
            while (rp > lp && nums[rp - 1] == nums[rp]) { rp--; }
            while (rp > lp && nums[lp + 1] == nums[lp]) { lp++; }
            rp--;
            lp++;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
