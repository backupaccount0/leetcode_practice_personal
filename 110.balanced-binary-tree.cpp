// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem110.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (48.31%)
 * Likes:    8231
 * Dislikes: 467
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
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
  bool isBalanced(TreeNode* root) {
    if (!root) { return true; }
    return isBalanced(root->left) && isBalanced(root->right) && abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
  }

 private:
  int maxDepth(TreeNode* node) {
    if (!node) { return 0; }
    return max(maxDepth(node->left), maxDepth(node->right)) + 1;
  }
};
// @lc code=end
