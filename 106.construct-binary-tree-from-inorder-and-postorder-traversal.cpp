// @before-stub-for-debug-begin
#include <algorithm>
#include <string>
#include <vector>
#include "commoncppproblem106.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (57.61%)
 * Likes:    5694
 * Dislikes: 85
 * Total Accepted:    458.5K
 * Total Submissions: 792.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder
 * traversal of a binary tree and postorder is the postorder traversal of the
 * same tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
 *
 *
 */

// // @lc code=start
// /**
//  * Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };
//  */

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* root = new TreeNode();
    helper(root, inorder, postorder);
    return root;
  }

  //   void PrintSpaces(int count) {
  //     for (int i = 0; i < count; i++) { std::cout << " "; }
  //   }

  //   int count = 0;

  //   void PrintVector(const std::string& str, const vector<int>& vec) {
  //     std::cout << str << " ";
  //     for (auto num : vec) { std::cout << num << " "; }
  //     std::cout << std::endl;
  //   }
 private:
  void helper(TreeNode* node, vector<int>& inorder, vector<int>& postorder) {
    // base case
    if (inorder.size() == 1) {
      node->val = postorder.back();
      return;
    }

    node->val = postorder.back();

    int sub_root_inorder_index = find(inorder.begin(), inorder.end(), node->val) - inorder.begin();

    vector<int> inorder_left(inorder.begin(), inorder.begin() + sub_root_inorder_index);
    vector<int> inorder_right(inorder.begin() + sub_root_inorder_index + 1, inorder.end());

    vector<int> postorder_left(postorder.begin(), postorder.begin() + sub_root_inorder_index);
    vector<int> postorder_right(postorder.begin() + sub_root_inorder_index, postorder.end() - 1);

    if (!inorder_left.empty()) {
      TreeNode* node_left = new TreeNode();
      node->left = node_left;
      helper(node_left, inorder_left, postorder_left);
    }
    if (!inorder_right.empty()) {
      TreeNode* node_right = new TreeNode();
      node->right = node_right;
      helper(node_right, inorder_right, postorder_right);
    }
  }
};
// @lc code=end
