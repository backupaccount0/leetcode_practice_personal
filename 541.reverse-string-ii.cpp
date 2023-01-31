/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      int lp = i, rp = i + k - 1;
      if (rp >= s.size()) { rp = s.size() - 1; }
      while (lp < rp) { swap(s[lp++], s[rp--]); }
    }
    return s;
  }
};
// @lc code=end
