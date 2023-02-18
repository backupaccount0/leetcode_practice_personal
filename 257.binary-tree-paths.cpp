// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem257.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (60.78%)
 * Likes:    5401
 * Dislikes: 231
 * Total Accepted:    593.5K
 * Total Submissions: 971.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any
 * order.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: ["1"]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 100].
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
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    vector<int> path;
    traversal(root, res, path);
    return res;
  }

 private:
  void traversal(TreeNode* node, vector<string>& res, vector<int>& path) {
    if (!node->left && !node->right) {
      path.push_back(node->val);
      string path_str;
      for (int i = 0; i < path.size() - 1; ++i) { path_str += to_string(path[i]) + "->"; }
      path_str += to_string(path[path.size() - 1]);
      res.push_back(path_str);
      return;
    }

    path.push_back(node->val);
    if (node->left) {
      traversal(node->left, res, path);
      path.pop_back();
    }
    if (node->right) {
      traversal(node->right, res, path);
      path.pop_back();
    }
  }
};
// @lc code=end
