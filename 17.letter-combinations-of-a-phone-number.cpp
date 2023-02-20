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
    if (digits.empty()) { return {}; }
    vector<string> res;
    string path;
    backtracking(res, path, digits, 0);
    return res;
  }

 private:
  void backtracking(vector<string>& res, string& path, string& digits, int start_index) {
    if (path.size() == digits.size()) {
      res.push_back(path);
      return;
    }

    string candidates = digit2letter_map.at(digits[start_index] - '0' - 2);
    for (int i = 0; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      backtracking(res, path, digits, start_index + 1);
      path.pop_back();
    }
  }

 private:
  vector<string> digit2letter_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end
