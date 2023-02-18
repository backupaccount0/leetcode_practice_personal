// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem102.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.47%)
 * Likes:    12211
 * Dislikes: 240
 * Total Accepted:    1.7M
 * Total Submissions: 2.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
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

// recursion
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) { return {}; }
    queue<TreeNode*> que;
    que.push(root);
    vector<vector<int>> res;
    traversalLevel(que, res);
    return res;
  }
  void traversalLevel(queue<TreeNode*>& que, vector<vector<int>>& res) {
    if (que.empty()) { return; }
    vector<int> level_res;
    int s = que.size();
    for (int i = 0; i < s; ++i) {
      level_res.push_back(que.front()->val);
      if (que.front()->left) { que.push(que.front()->left); }
      if (que.front()->right) { que.push(que.front()->right); }
      que.pop();
    }
    res.push_back(level_res);
    traversalLevel(que, res);
  }
};

// // iteration
// class Solution {
//  public:
//   vector<vector<int>> levelOrder(TreeNode* root) {
//     if (!root) { return {}; }
//     queue<TreeNode*> que;
//     que.push(root);
//     vector<vector<int>> res;
//     while (!que.empty()) {
//       int s = que.size();
//       vector<int> level_res;
//       for (int i = 0; i < s; ++i) {
//         level_res.push_back(que.front()->val);
//         if (que.front()->left) { que.push(que.front()->left); }
//         if (que.front()->right) { que.push(que.front()->right); }
//         que.pop();
//       }
//       res.push_back(level_res);
//     }
//     return res;
//   }
// };
// @lc code=end
