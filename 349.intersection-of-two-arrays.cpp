/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (70.64%)
 * Likes:    4208
 * Dislikes: 2070
 * Total Accepted:    801.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> interscetion_nums;
    unordered_set<int> nums2_set;
    for (auto i : nums2) { nums2_set.emplace(i); }

    for (auto i : nums1) {
      if (nums2_set.find(i) != nums2_set.end()) { interscetion_nums.emplace(i); }
    }
    vector<int> res(interscetion_nums.begin(), interscetion_nums.end());

    return res;
  }
};
// @lc code=end
