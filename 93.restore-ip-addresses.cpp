// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (43.51%)
 * Likes:    3248
 * Dislikes: 663
 * Total Accepted:    331.3K
 * Total Submissions: 759.4K
 * Testcase Example:  '"25525511135"'
 *
 * A valid IP address consists of exactly four integers separated by single
 * dots. Each integer is between 0 and 255 (inclusive) and cannot have leading
 * zeros.
 *
 *
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses.
 *
 *
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be formed by inserting dots into s. You are not allowed
 * to reorder or remove any digits in s. You may return the valid IP addresses
 * in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 *
 *
 * Example 3:
 *
 *
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * s consists of digits only.
 *
 *
 */
// @lc code=start

#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> solutions{};
    string state = "";
    Search(state, solutions, s);
    return solutions;
  }

 private:
  bool IsValidState(string state, string s) { return (state.size() == s.size() + 3); }
  string GetCandidate(string state, string s) {
    int last_dot_index = state.rfind('.');
    if (last_dot_index == string::npos) { last_dot_index = -1; }
    string sub_str;
    sub_str = state.substr(last_dot_index + 1, state.size());
    string candidate;
    int num_dots = count(state.begin(), state.end(), '.');
    if (state.size() >= s.size() + 3) {
      candidate = "";
    } else {
      if ((stoi(sub_str + s[state.size() - num_dots]) < 256) && (sub_str != "0") &&
          (s.substr(state.size() - num_dots, s.size()).size() > (3 - num_dots))) {
        candidate.push_back(s[state.size() - num_dots]);
      }
      if (sub_str != "" && num_dots < 3) { candidate.push_back('.'); }
    }
    return candidate;
  }
  void Search(string state, vector<string>& solutions, string s) {
    if (IsValidState(state, s)) {
      solutions.push_back(state);
      return;
    }
    string candidate = GetCandidate(state, s);
    for (auto c : candidate) {
      state.push_back(c);
      Search(state, solutions, s);
      state.pop_back();
    }
  }
};
// @lc code=end
