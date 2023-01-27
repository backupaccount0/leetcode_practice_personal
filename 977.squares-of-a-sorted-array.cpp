/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.91%)
 * Likes:    7189
 * Dislikes: 179
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 *
 *
 *
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */

// @lc code=start
#include <math.h>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int left_index = 0, right_index = nums.size() - 1;
    vector<int> res = nums;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int left_square = pow(nums[left_index], 2);
      int right_square = pow(nums[right_index], 2);
      if (left_square >= right_square) {
        res[i] = left_square;
        left_index += 1;
      } else {
        res[i] = right_square;
        right_index -= 1;
      }
    }
    return res;
  }
};
// @lc code=end
