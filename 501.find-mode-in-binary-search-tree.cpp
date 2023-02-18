// @before-stub-for-debug-begin
#include <climits>
#include <string>
#include <vector>
#include "commoncppproblem501.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode_-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (48.80%)
 * Likes:    2756
 * Dislikes: 634
 * Total Accepted:    183.5K
 * Total Submissions: 373.7K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given the root of a binary search tree (BST) with duplicates, return all the
 * mode_(s) (i.e., the most frequently occurred element) in it.
 *
 * If the tree has more than one mode_, return them in any order.
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
  vector<int> findMode(TreeNode* root) {
    traversal(root);
    return mode_;
  }

 private:
  void traversal(TreeNode* node) {
    if (!node) { return; }

    traversal(node->left);

    if (node->val == last_node_val_) {
      cur_val_count_++;
    } else {
      cur_val_count_ = 1;
    }

    if (cur_val_count_ >= max_count_) {
      if (cur_val_count_ > max_count_) {
        max_count_ = cur_val_count_;
        mode_.clear();
      }
      mode_.push_back(node->val);
    }

    last_node_val_ = node->val;
    traversal(node->right);
  }

 private:
  vector<int> mode_;
  int max_count_ = 0;
  int cur_val_count_;
  int last_node_val_ = INT_MIN;
};
// @lc code=end
