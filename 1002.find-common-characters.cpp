/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.41%)
 * Likes:    2843
 * Dislikes: 234
 * Total Accepted:    169.7K
 * Total Submissions: 248.1K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given a string array words, return an array of all characters that show up
 * in all strings within the words (including duplicates). You may return the
 * answer in any order.
 *
 *
 * Example 1:
 * Input: words = ["bella","label","roller"]
 * Output: ["e","l","l"]
 * Example 2:
 * Input: words = ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<vector<int>> letter_counts;
    for (auto word : words) {
      vector<int> letter_count(26, 0);
      for (auto ch : word) { letter_count[ch - 'a'] += 1; }
      letter_counts.emplace_back(letter_count);
    }

    vector<string> repeated_letters;
    int s = words.size();
    for (int k = 0; k < letter_counts[0].size(); ++k) {
      int min_count = 100;
      for (int i = 0; i < letter_counts.size(); ++i) {
        if (letter_counts[i][k] < min_count) { min_count = letter_counts[i][k]; }
      }
      while (min_count--) { repeated_letters.push_back(string(1, static_cast<char>('a' + k))); }
    }
    return repeated_letters;
  }
};
// @lc code=end
