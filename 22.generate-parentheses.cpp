// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (71.92%)
 * Likes:    16107
 * Dislikes: 627
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> solutions{};
    string state = "";
    Search(state, solutions, n);
    return solutions;
  }

 private:
  bool IsStateValid(string state, int n) { return state.size() == (2 * n); }
  vector<char> GetCandidate(const string& state, int n) {
    int left = 0, right = 0;
    for (auto i : state) { (i == '(') ? left += 1 : right += 1; }
    vector<char> candidate;
    if ((left - right) >= 0 && state.size() < 2 * n) {
      if ((left - right) == 0) {
        candidate.push_back('(');
      } else {
        candidate.push_back(')');
        if ((left - right) < n && (left < n)) { candidate.push_back('('); }
      }
    }
    return candidate;
  }

  void Search(string state, vector<string>& solutions, int n) {
    if (IsStateValid(state, n)) {
      solutions.push_back(state);
      return;
    }
    vector<char> candidate = GetCandidate(state, n);
    for (auto ch : candidate) {
      state.push_back(ch);
      Search(state, solutions, n);
      state.pop_back();
    }
  }
};
