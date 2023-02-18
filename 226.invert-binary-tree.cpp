/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (73.45%)
 * Likes:    10870
 * Dislikes: 153
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
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
// recursion
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    traversal(root);
    return root;
  }

 private:
  void traversal(TreeNode* node) {
    if (!node || (!node->left && !node->right)) { return; }
    traversal(node->left);
    traversal(node->right);
    swap(node->left, node->right);
  }
};

// // level order traversal
// class Solution {
//  public:
//   TreeNode* invertTree(TreeNode* root) {
//     if (!root) { return root; }
//     queue<TreeNode*> que;
//     que.push(root);
//     while (!que.empty()) {
//       int s = que.size();
//       for (int i = 0; i < s; ++i) {
//         TreeNode* tmp = que.front()->left;
//         que.front()->left = que.front()->right;
//         que.front()->right = tmp;
//         if (que.front()->left) { que.push(que.front()->left); }
//         if (que.front()->right) { que.push(que.front()->right); }
//         que.pop();
//       }
//     }
//     return root;
//   }
// };
// @lc code=end
