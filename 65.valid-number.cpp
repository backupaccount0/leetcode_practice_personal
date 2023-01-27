// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem65.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (18.61%)
 * Likes:    791
 * Dislikes: 1369
 * Total Accepted:    293.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '"0"'
 *
 * A valid number can be split up into these components (in order):
 *
 *
 * A decimal number or an integer.
 * (Optional) An 'e' or 'E', followed by an integer.
 *
 *
 * A decimal number can be split up into these components (in order):
 *
 *
 * (Optional) A sign character (either '+' or '-').
 * One of the following formats:
 *
 * One or more digits, followed by a dot '.'.
 * One or more digits, followed by a dot '.', followed by one or more
 * digits.
 * A dot '.', followed by one or more digits.
 *
 *
 *
 *
 * An integer can be split up into these components (in order):
 *
 *
 * (Optional) A sign character (either '+' or '-').
 * One or more digits.
 *
 *
 * For example, all the following are valid numbers: ["2", "0089", "-0.1",
 * "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93",
 * "-123.456e789"], while the following are not valid numbers: ["abc", "1a",
 * "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 *
 * Given a string s, return true if s is a valid number.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "0"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "e"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s = "."
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * s consists of only English letters (both uppercase and lowercase), digits
 * (0-9), plus '+', minus '-', or dot '.'.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isNumber(string s) {
    bool have_dot = false;
    bool have_e = false;
    bool have_sign1 = false;
    bool have_sign2 = false;
    int e_index = 0;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '.') {
        if (!have_dot) {
          have_dot = true;
        } else {
          return false;
        }
      } else if (tolower(s[i]) == 'e') {
        if (!have_e) {
          have_e = true;
          e_index = i;
        } else {
          return false;
        }
      } else if (s[i] == '+' || s[i] == '-') {
        if (!have_sign1) {
          if (i == 0 && !have_e) {
            have_sign1 = true;
          } else if (have_e && i == (e_index + 1)) {
            have_sign2 = true;
          } else {
            return false;
          }
        } else if (have_sign1 && !have_sign2) {
          if (have_e) {
            have_sign2 = true;
          } else {
            return false;
          }
        } else if (have_sign2) {
          return false;
        }
      }
    }

    string dec_str = "", int_str = "";

    if (have_e) {
      dec_str = s.substr(0, e_index);
      int_str = s.substr(e_index + 1);
      if (e_index == (s.size() - 1)) { return false; }
    } else {
      dec_str = s;
    }

    if (dec_str.empty()) { return false; }
    bool have_digit = false;
    for (int i = 0; i < dec_str.size(); ++i) {
      if (!isdigit(dec_str[i])) {
        if (!(dec_str[i] == '+' || dec_str[i] == '-' || dec_str[i] == '.')) {
          return false;
        } else if (i == 0 && dec_str.size() == 1) {
          return false;
        }
      } else {
        have_digit = true;
      }
    }
    if (!have_digit) { return false; }

    if (!int_str.empty()) {
      if (int_str.size() == 1 && !isdigit(int_str[0])) {
        return false;
      } else {
        for (int i = 0; i < int_str.size(); ++i) {
          if (!isdigit(int_str[i])) {
            if (!(i == 0 && (int_str[i] == '+' || int_str[i] == '-'))) {
              cout << i << int_str[i] << endl;
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end
