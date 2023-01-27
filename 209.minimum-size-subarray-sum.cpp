/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.58%)
 * Likes:    8559
 * Dislikes: 237
 * Total Accepted:    651K
 * Total Submissions: 1.5M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int min_size = __INT32_MAX__;
    int win_left = 0, sum = 0;
    for (int win_right = 0; win_right < nums.size(); ++win_right) {
      sum += nums[win_right];
      while (sum >= target) {
        if (win_right - win_left < min_size) { min_size = win_right - win_left + 1; }
        sum -= nums[win_left];
        win_left++;
      }
    }
    return min_size == __INT32_MAX__ ? 0 : min_size;
  }
};
// @lc code=end
