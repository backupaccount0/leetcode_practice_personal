// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (66.91%)
 * Likes:    5541
 * Dislikes: 164
 * Total Accepted:    900.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
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
 * The number of the nodes in the tree is in the range [0, 100].
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
//   vector<int> postorderTraversal(TreeNode* root) {
//     if (!root) { return {}; }
//     vector<int> res;
//     stack<TreeNode*> st;
//     st.push(root);
//     while (!st.empty()) {
//       TreeNode* cur_node = st.top();
//       res.push_back(cur_node->val);
//       st.pop();
//       if (cur_node->left) { st.push(cur_node->left); }
//       if (cur_node->right) { st.push(cur_node->right); }
//     }
//     reverse(res.begin(), res.end());
//     return res;
//   }
// };

// recursion
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {}

 private:
  void traversal(TreeNode* node, vector<int> res) {
    if (!node) { return; }
    if (node->left) { traversal(node->left, res); }
    if (node->right) { traversal(node->right, res); }
    res.push_back(node->val);
  }
};
// @lc code=end
