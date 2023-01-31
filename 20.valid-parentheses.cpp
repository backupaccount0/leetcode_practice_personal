// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.59%)
 * Likes:    17773
 * Dislikes: 985
 * Total Accepted:    3M
 * Total Submissions: 7.4M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

// @lc code=start
#include <stack>
class Solution {
 public:
  bool isValid(string s) {
    if (s.empty() || s.size() % 2 != 0) { return false; }
    if (!(s[0] == '[' || s[0] == '{' || s[0] == '(')) { return false; }
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push(')');
      } else if (s[i] == '{') {
        st.push('}');
      } else if (s[i] == '[') {
        st.push(']');
      } else if (st.empty() || st.top() != s[i]) {
        return false;
      } else {
        st.pop();
      }
    }
    return st.empty();
  }
};
// @lc code=end
