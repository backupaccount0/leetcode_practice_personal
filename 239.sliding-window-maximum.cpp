// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (46.59%)
 * Likes:    13444
 * Dislikes: 434
 * Total Accepted:    717.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 *
 * Return the max sliding window.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start

class MonoQue {
 public:
  void push(int val) {
    while (!que.empty() && que.back() < val) { que.pop_back(); }
    que.push_back(val);
  }
  void pop(int val) {
    if (!que.empty() && que.front() == val) { que.pop_front(); }
  }
  int front() { return que.front(); }

 private:
  deque<int> que;
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonoQue mono_que;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k - 1) {
        mono_que.push(nums[i]);
      } else {
        mono_que.push(nums[i]);
        res.push_back(mono_que.front());
        mono_que.pop(nums[i - k + 1]);
      }
    }
    return res;
  }
};
// @lc code=end
