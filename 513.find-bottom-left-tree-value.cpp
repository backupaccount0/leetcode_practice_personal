/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (66.51%)
 * Likes:    2734
 * Dislikes: 235
 * Total Accepted:    204.1K
 * Total Submissions: 305.9K
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, return the leftmost value in the last row
 * of the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
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

// iteration
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);
    int res;
    while (!que.empty()) {
      int s = que.size();
      res = que.front()->val;
      for (int i = 0; i < s; ++i) {
        if (que.front()->left) { que.push(que.front()->left); }
        if (que.front()->right) { que.push(que.front()->right); }
        que.pop();
      }
    }
    return res;
  }
};
// @lc code=end
