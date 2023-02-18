/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (64.63%)
 * Likes:    2522
 * Dislikes: 93
 * Total Accepted:    220.1K
 * Total Submissions: 340.6K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return an array of the largest value in
 * each row of the tree (0-indexed).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,2,5,3,null,9]
 * Output: [1,3,9]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3]
 * Output: [1,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree will be in the range [0, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    if (!root) { return {}; }
    vector<int> res;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      int s = que.size();
      int max = INT_MIN;
      for (int i = 0; i < s; ++i) {
        if (que.front()->val > max) { max = que.front()->val; }
        if (que.front()->left) { que.push(que.front()->left); }
        if (que.front()->right) { que.push(que.front()->right); }
        que.pop();
      }
      res.push_back(max);
    }
    return res;
  }
};
// @lc code=end
