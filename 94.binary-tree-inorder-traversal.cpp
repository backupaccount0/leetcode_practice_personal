/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (73.17%)
 * Likes:    10722
 * Dislikes: 516
 * Total Accepted:    1.9M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
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
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

// // iteration
// class Solution {
//  public:
//   vector<int> inorderTraversal(TreeNode* root) {
//     if (!root) { return {}; }
//     vector<int> res;
//     stack<TreeNode*> st;
//     TreeNode* cur_node = root;
//     while (!st.empty() || cur_node) {
//       if (cur_node) {
//         st.push(cur_node);
//         cur_node = cur_node->left;
//       }
//       if (!cur_node) {
//         res.push_back(st.top()->val);
//         cur_node = st.top()->right;
//         st.pop();
//       }
//     }
//     return res;
//   }
// };
// recursion
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    traversal(root, res);
    return res;
  }

 private:
  void traversal(TreeNode* node, vector<int>& res) {
    if (!node) { return; }
    if (node->left) { traversal(node->left, res); }
    res.push_back(node->val);
    if (node->right) { traversal(node->right, res); }
  }
};
// @lc code=end
