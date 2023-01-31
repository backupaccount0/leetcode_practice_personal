// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (31.91%)
 * Likes:    5380
 * Dislikes: 4475
 * Total Accepted:    880K
 * Total Submissions: 2.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int sp = 0, fp = 0;
    while (fp < s.size()) {
      if (!isblank(s[fp])) {
        if (sp) { s[sp++] = ' '; }
        while (fp < s.size() && !isblank(s[fp])) { s[sp++] = s[fp++]; }
      }
      fp++;
    }
    s.resize(sp);

    int lp = 0, rp = s.size() - 1;
    while (rp > lp) { swap(s[lp++], s[rp--]); }

    lp = rp = 0;
    while (rp < s.size()) {
      while (rp < s.size() && !isblank(s[rp])) { rp++; }
      int tmp = rp--;
      while (rp > lp) { swap(s[lp++], s[rp--]); }
      lp = rp = tmp + 1;
    }
    return s;
  }
};
// @lc code=end
