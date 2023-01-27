/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (62.93%)
 * Likes:    8072
 * Dislikes: 261
 * Total Accepted:    1.9M
 * Total Submissions: 3.1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> letter_record(26, 0);
    for (auto ch : s) { letter_record[ch - 'a'] += 1; }
    for (auto ch : t) { letter_record[ch - 'a'] -= 1; }
    for (auto i : letter_record) {
      if (i != 0) { return false; }
    }
    return true;
  }
};
// @lc code=end
