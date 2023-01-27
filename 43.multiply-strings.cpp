/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
 public:
  string multiply(string num1, string num2) {
    int s1 = num1.size();
    int s2 = num2.size();

    std::string res(s1 + s2, '0');
    for (int i = num2.size() - 1; i >= 0; --i) {
      for (int j = num1.size() - 1; j >= 0; --j) {
        int sum = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
        res[i + j + 1] = (sum % 10 + '0');
        res[i + j] += (sum / 10);
      }
    }
    for (int i = 0; i < res.size(); ++i) {
      if (res[i] != '0') { return res.substr(i); }
    }
    return "0";
  }
};
// @lc code=end
