// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (53.07%)
 * Likes:    12116
 * Dislikes: 274
 * Total Accepted:    1.5M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
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
  bool isSymmetric(TreeNode* root) {
    if (!root->left && !root->right) { return true; }
    return compareNode(root->left, root->right);
  }

  bool compareNode(TreeNode* node_left, TreeNode* node_right) {
    if (!node_left && !node_right) { return true; }
    if (!node_left || !node_right) { return false; }

    bool comp1 = compareNode(node_left->left, node_right->right);
    bool comp2 = compareNode(node_left->right, node_right->left);
    return comp1 && comp2 && node_left->val == node_right->val;
  }
};
// // iteration
// class Solution {
//  public:
//   bool isSymmetric(TreeNode* root) {
//     if (!root->left && !root->right) { return true; }
//     queue<TreeNode*> que_left;
//     que_left.push(root->left);
//     queue<TreeNode*> que_right;
//     que_right.push(root->right);

//     while (!que_left.empty()) {
//       int s = que_left.size();
//       for (int i = 0; i < s; ++i) {
//         if (que_left.front() && que_right.front()) {
//           if (que_left.front()->val != que_right.front()->val) { return false; }
//           que_left.push(que_left.front()->left);
//           que_left.push(que_left.front()->right);
//           que_right.push(que_right.front()->right);
//           que_right.push(que_right.front()->left);
//         } else if (!que_left.front() && !que_right.front()) {
//         } else {
//           return false;
//         }
//         que_left.pop();
//         que_right.pop();
//       }
//     }
//     return true;
//   }
// };
// @lc code=end
