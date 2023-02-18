// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (60.95%)
 * Likes:    12061
 * Dislikes: 357
 * Total Accepted:    921.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = new TreeNode();
    helper(root, preorder, inorder, 0, 0, preorder.size());
    return root;
  }

 private:
  void helper(
      TreeNode* node,
      const vector<int>& preorder,
      const vector<int>& inorder,
      int inorder_begin,
      int preorder_begin,
      int path_size) {
    if (path_size == 1) {
      node->val = preorder.at(preorder_begin);
      return;
    }

    node->val = preorder.at(preorder_begin);

    int sub_root_inorder_index =
        find(inorder.begin() + inorder_begin, inorder.begin() + inorder_begin + path_size, node->val) - inorder.begin();

    int left_inorder_begin = inorder_begin;
    int left_path_size = sub_root_inorder_index - inorder_begin;
    int left_preorder_begin = preorder_begin + 1;

    int right_inorder_begin = sub_root_inorder_index + 1;
    int right_path_size = path_size - left_path_size - 1;
    int right_preorder_begin = preorder_begin + left_path_size + 1;

    if (left_path_size) {
      TreeNode* left_node = new TreeNode();
      node->left = left_node;
      helper(node->left, preorder, inorder, left_inorder_begin, left_preorder_begin, left_path_size);
    }

    if (right_path_size) {
      TreeNode* right_node = new TreeNode();
      node->right = right_node;
      helper(node->right, preorder, inorder, right_inorder_begin, right_preorder_begin, right_path_size);
    }
  }
};
// @lc code=end
