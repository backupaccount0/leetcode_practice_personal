/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (56.79%)
 * Likes:    2619
 * Dislikes: 140
 * Total Accepted:    192.2K
 * Total Submissions: 338.2K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,6,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 *
 *
 *
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
  int getMinimumDifference(TreeNode* root) {
    traversal(root);
    return min_diff_;
  }
  void traversal(TreeNode* node) {
    if (!node) { return; }
    traversal(node->left);
    if (last_node_val_ != INT_MIN) {
      int diff = abs(node->val - last_node_val_);
      if (diff < min_diff_) { min_diff_ = diff; }
    }
    last_node_val_ = node->val;
    traversal(node->right);
  }

 private:
  int last_node_val_ = INT_MIN;
  int min_diff_ = INT_MAX;
};
// @lc code=end
