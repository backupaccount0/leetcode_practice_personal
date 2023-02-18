/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (47.76%)
 * Likes:    7816
 * Dislikes: 912
 * Total Accepted:    1.1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return true if the
 * tree has a root-to-leaf path such that adding up all the values along the
 * path equals targetSum.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 * Explanation: The root-to-leaf path with the target sum is shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 * Explanation: There two root-to-leaf paths in the tree:
 * (1 --> 2): The sum is 3.
 * (1 --> 3): The sum is 4.
 * There is no root-to-leaf path with sum = 5.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [], targetSum = 0
 * Output: false
 * Explanation: Since the tree is empty, there are no root-to-leaf paths.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) { return false; }
    vector<int> path;
    return traversal(root, path, targetSum);
  }
  bool traversal(TreeNode* node, vector<int>& path, int targetSum) {
    if (!node->left && !node->right) {
      path.push_back(node->val);
      if (accumulate(path.begin(), path.end(), 0) == targetSum) { return true; }
      return false;
    }
    path.push_back(node->val);
    if (node->left) {
      if (traversal(node->left, path, targetSum)) { return true; }
      path.pop_back();
    }
    if (node->right) {
      if (traversal(node->right, path, targetSum)) { return true; }
      path.pop_back();
    }
    return false;
  }
};

// @lc code=end
