// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (54.67%)
 * Likes:    7877
 * Dislikes: 985
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is happy.
 *
 * A happy number is a number defined by the following process:
 *
 *
 * Starting with any positive integer, replace the number by the sum of the
 * squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), or it
 * loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 *
 *
 * Return true if n is a happy number, and false if not.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
#include <unordered_set>
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> sums;
    int sum = n;
    while (true) {
      n = sum;
      sum = 0;
      for (auto ch : to_string(n)) { sum += (ch - '0') * (ch - '0'); }
      if (sums.find(sum) != sums.end()) { return false; }
      if (sum == 1) { return true; }
      sums.emplace(sum);
    }
  }
};
// @lc code=end
