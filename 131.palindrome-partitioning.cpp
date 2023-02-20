// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem131.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (62.67%)
 * Likes:    10198
 * Dislikes: 324
 * Total Accepted:    617.3K
 * Total Submissions: 955.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backtracking(res, path, s, 0);
    return res;
  }

private:
  void backtracking(vector<vector<string>> &res, vector<string> &path,
                    string &s, int start_index) {
    if (isVaild(path)) {
      if (len_ == s.size()) {
        res.push_back(path);
        return;
      }
    } else {
      return;
    }

    for (int i = 1; i <= s.size() - start_index; ++i) {
      path.push_back(s.substr(start_index, i));
      len_ += i;
      backtracking(res, path, s, start_index + i);
      path.pop_back();
      len_ -= i;
    }
  }
  bool isVaild(vector<string> &path) {
    int left, right;
    for (auto ss : path) {
      left = 0;
      right = ss.size() - 1;
      while (right > left) {
        if (ss[left++] != ss[right--]) {
          return false;
        }
      }
    }
    return true;
  }

private:
  int len_ = 0;
};
// @lc code=end
