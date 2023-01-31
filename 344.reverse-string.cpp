// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem344.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      swap(s[left++], s[right--]);
    }
  }
};
// @lc code=end
