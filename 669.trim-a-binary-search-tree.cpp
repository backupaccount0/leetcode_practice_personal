/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
 *
 * https://leetcode.com/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (66.33%)
 * Likes:    5271
 * Dislikes: 247
 * Total Accepted:    260.2K
 * Total Submissions: 392.1K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * Given the root of a binary search tree and the lowest and highest boundaries
 * as low and high, trim the tree so that all its elements lies in [low, high].
 * Trimming the tree should not change the relative structure of the elements
 * that will remain in the tree (i.e., any node's descendant should remain a
 * descendant). It can be proven that there is a unique answer.
 *
 * Return the root of the trimmed binary search tree. Note that the root may
 * change depending on the given bounds.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,0,2], low = 1, high = 2
 * Output: [1,null,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
 * Output: [3,2,null,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
 * The value of each node in the tree is unique.
 * root is guaranteed to be a valid binary search tree.
 * 0 <= low <= high <= 10^4
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
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) { return root; }
    if (root->val < low) {
      if (!root->right) {
        root = nullptr;
      } else {
        root = trimBST(root->right, low, high);
      }
      return root;
    } else if (root->val > high) {
      if (!root->left) {
        root = nullptr;
      } else {
        root = trimBST(root->left, low, high);
      }
      return root;
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};
// @lc code=end
