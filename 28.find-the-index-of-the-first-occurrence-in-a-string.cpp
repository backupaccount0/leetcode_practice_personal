// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 *
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Medium (37.72%)
 * Likes:    1404
 * Dislikes: 99
 * Total Accepted:    1.5M
 * Total Submissions: 4M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of
 * haystack.
 *
 *
 * Example 1:
 *
 *
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int strStr(string haystack, string needle) {
    vector<int> next = getNext(needle);
    int j = 0;
    for (int i = 0; i < haystack.size();) {
      while (i < haystack.size() && haystack[i] == needle[j]) {
        i++;
        j++;
      }
      if (j == needle.size()) { return i - j; }
      if (j) {
        j = next[j - 1];
      } else {
        i++;
      }
    }
    return -1;
  }

 private:
  vector<int> getNext(const string pattern) {
    vector<int> next(pattern.size(), 0);
    int k = 0;
    for (int i = 1; i < pattern.size(); ++i) {
      while (j > 0 && pattern[i] != pattern[j]) { j = next[j - 1]; }
      if (pattern[i] == pattern[j]) { j++; }
      next[i] = j;
    }
    return next;
  }
};

// @lc code=end
