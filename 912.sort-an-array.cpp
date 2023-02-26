// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem912.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (58.64%)
 * Likes:    3322
 * Dislikes: 606
 * Total Accepted:    359.9K
 * Total Submissions: 616.6K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order and
 * return it.
 *
 * You must solve the problem without using any built-in functions in
 * O(nlog(n)) time complexity and with the smallest space complexity
 * possible.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Explanation: After sorting the array, the positions of some numbers are not
 * changed (for example, 2 and 3), while the positions of other numbers are
 * changed (for example, 1 and 5).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * Explanation: Note that the values of nums are not necessairly unique.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start

// // Bubble Sort
// class Solution {
//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     bool flag = true;
//     int count = 0;
//     while (flag) {
//       flag = false;
//       for (int i = 1; i < nums.size() - count; ++i) {
//         if (nums[i] < nums[i - 1]) {
//           flag = true;
//           swap(nums[i], nums[i - 1]);
//         }
//       }
//       count++;
//     }
//     return nums;
//   }
// };

// // Selection sort
// class Solution {
//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     int min_index;
//     for (int i = 0; i < nums.size(); ++i) {
//       min_index = i;
//       for (int j = i; j < nums.size(); ++j) {
//         if (nums[j] < nums[min_index]) { min_index = j; }
//       }
//       if (min_index != i) { swap(nums[i], nums[min_index]); }
//     }
//     return nums;
//   }
// };

// // Insert sort
// class Solution {
//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     for (int i = 1; i < nums.size(); ++i) {
//       for (int j = i; j > 0; --j) {
//         if (nums[j - 1] > nums[j]) {
//           swap(nums[j], nums[j - 1]);
//         } else {
//           break;
//         }
//       }
//     }
//     return nums;
//   }
// };

// // Shell sort
// class Solution {
//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     int gap = 1;
//     while (3 * gap + 1 < nums.size()) { gap = 3 * gap + 1; }
//     for (gap; gap >= 1; gap = (gap - 1) / 3) {
//       for (int i = gap; i < nums.size(); i++) {
//         for (int j = i; j >= gap; j -= gap) {
//           if (nums[j] < nums[j - gap]) {
//             swap(nums[j], nums[j - gap]);
//           } else {
//             break;
//           }
//         }
//       }
//     }
//     return nums;
//   }
// };

// // Merge Sort
// class Solution {
//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     vector<int> res;
//     res = helper(nums, 0, nums.size());
//     return res;
//   }

//  private:
//   vector<int> helper(const vector<int>& nums, int begin_index, int sz) {
//     if (sz == 1) {
//       vector<int> res{nums[begin_index]};
//       return res;
//     }

//     if (sz == 2) {
//       vector<int> res{nums[begin_index], nums[begin_index + 1]};
//       if (nums[begin_index] > nums[begin_index + 1]) { reverse(res.begin(), res.end()); }
//       return res;
//     }

//     vector<int> vec_left = helper(nums, begin_index, sz / 2 + sz % 2);
//     vector<int> vec_right = helper(nums, begin_index + sz / 2 + sz % 2, sz - (sz / 2 + sz % 2));

//     vector<int> res;
//     int left = 0, right = 0;
//     while (left < vec_left.size() && right < vec_right.size()) {
//       if (vec_left[left] <= vec_right[right]) {
//         res.push_back(vec_left[left++]);
//       } else {
//         res.push_back(vec_right[right++]);
//       }
//     }
//     if (left == vec_left.size()) {
//       while (right < vec_right.size()) { res.push_back(vec_right[right++]); }
//     } else {
//       while (left < vec_left.size()) { res.push_back(vec_left[left++]); }
//     }
//     return res;
//   }
// };

//
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {}
  helper(vector<int>& nums, int begin_index, int sz) {
    int left_begin = begin_index;
    int left_size = sz / 2;
    int pivot_index = begin_index + sz / 2;
    int right_begin = pivot_index + 1;
    int right_size = sz - left_size - 1;

    helper(nums, left_begin, left_size);
    helper(nums, right_begin, right_size);

  }
};

// //
// class Solution {
//  public:
//   vector<int> sortArray(vector<int>& nums) {}
// };
// @lc code=end
