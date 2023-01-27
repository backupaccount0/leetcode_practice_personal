// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.65%)
 * Likes:    13366
 * Dislikes: 780
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

// @lc code=start
#include <map>
using namespace std;
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> solutions{};
    if (digits.empty()) { return solutions; }
    string state = "";
    Search(state, solutions, digits);
    return solutions;
  }

 private:
  bool IsStateValid(string state, string digits) { return state.size() == digits.size(); }
  string GetCandidate(string state, string digits) {
    string candidate = "";
    if (state.size() == digits.size()) { return candidate; }
    char num = digits[state.size()];
    candidate = letter_digit_map[num];
    return candidate;
  }
  void Search(string state, vector<string>& soultions, string digits) {
    if (IsStateValid(state, digits)) {
      soultions.push_back(state);
      return;
    }
    string candidate = GetCandidate(state, digits);
    for (auto c : candidate) {
      state.push_back(c);
      Search(state, soultions, digits);
      state.pop_back();
    }
  }

 private:
  const map<char, string> letter_digit_map{
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"},
  };
};
// @lc code=end
