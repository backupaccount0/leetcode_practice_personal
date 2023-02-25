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
    vector<string> res;
    vector<string> path;
    backtracking(res, path, s, 0);
    return res;
  }

 private:
  void backtracking(vector<string>& res, vector<string>& path, string& s, int start_index) {
    if (path.size() == 4 && len_ == s.size()) {
      res.push_back(vec2str(path));
      return;
    }

    if (path.size() > 4 || (s.size() - len_) / 3 > 4 - path.size()) { return; }

    int end = (s.size() - start_index > 3 ? 3 : s.size() - start_index);
    for (int i = 1; i <= end; ++i) {
      string sub_str = s.substr(start_index, i);
      if ((sub_str.front() == '0' && i > 1) || ((stoi(sub_str) < 0 || stoi(sub_str) > 255))) { return; }
      path.push_back(sub_str);
      len_ += i;
      backtracking(res, path, s, start_index + i);
      path.pop_back();
      len_ -= i;
    }
  }
  string vec2str(const vector<string>& vec) {
    string s;
    for (int i = 0; i < vec.size(); ++i) {
      s += vec[i];
      if (i < vec.size() - 1) { s += "."; }
    }
    return s;
  }

 private:
  int len_ = 0;
};
// @lc code=end
