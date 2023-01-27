/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (s.empty() || numRows == 1) { return s; }
    int str_len = s.size();
    string s_prime = "";
    int zig_nums = (str_len / (numRows * 2 - 2)) + 1;
    int repeat_nums = numRows * 2 - 2;
    for (int row = 0; row < numRows; ++row) {
      for (int j = 0; j < zig_nums; ++j) {
        int index = j * repeat_nums + row;
        if (index < str_len) { s_prime += s[index]; }
        if (row != 0 && row != (numRows - 1)) {
          {
            int index2 = j * repeat_nums + row + (numRows - row) * 2 - 2;
            if (index2 < str_len) { s_prime += s[index2]; }
          }
        }
      }
    }
    return s_prime;
  }
};
// @lc code=end
