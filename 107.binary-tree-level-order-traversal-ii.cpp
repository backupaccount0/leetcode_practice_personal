/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (60.38%)
 * Likes:    3939
 * Dislikes: 304
 * Total Accepted:    551.7K
 * Total Submissions: 912.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the bottom-up level order traversal
 * of its nodes' values. (i.e., from left to right, level by level from leaf to
 * root).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
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
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
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

using namespace std;
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> output;
    queue<TreeNode*> level_nodes;
    if (root) { level_nodes.push(root); }
    while (!level_nodes.empty()) {
      vector<int> level_results;
      int sz = level_nodes.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode* q = level_nodes.front();
        level_results.push_back(q->val);
        level_nodes.pop();
        if (q->left) { level_nodes.push(q->left); }
        if (q->right) { level_nodes.push(q->right); }
      }
      output.push_back(level_results);
    }
    reverse(output.begin(), output.end());
    return output;
  }
};
// @lc code=end
