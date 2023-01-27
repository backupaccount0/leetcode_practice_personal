/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (57.91%)
 * Likes:    3583
 * Dislikes: 397
 * Total Accepted:    686K
 * Total Submissions: 1.2M
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> mag_letter_count(26, 0);
    vector<int> ran_letter_count(26, 0);
    for (auto ch : magazine) { mag_letter_count[ch - 'a']++; }
    for (auto ch : ransomNote) { ran_letter_count[ch - 'a']++; }
    for (int i = 0; i < mag_letter_count.size(); ++i) {
      if (mag_letter_count[i] < ran_letter_count[i]) { return false; }
    }
    return true;
  }
};
// @lc code=end
