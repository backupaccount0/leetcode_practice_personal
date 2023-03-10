// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem450.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (50.03%)
 * Likes:    6973
 * Dislikes: 178
 * Total Accepted:    341.1K
 * Total Submissions: 679.6K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 *
 * Search for a node to remove.
 * If the node is found, delete the node.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 3
 * Output: [5,4,6,2,null,null,7]
 * Explanation: Given key to delete is 3. So we find the node with value 3 and
 * delete it.
 * One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 * Please notice that another valid answer is [5,2,6,null,4,null,7] and it's
 * also accepted.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 0
 * Output: [5,3,6,2,4,null,7]
 * Explanation: The tree does not contain a node with value = 0.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [], key = 0
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * Each node has a unique value.
 * root is a valid binary search tree.
 * -10^5 <= key <= 10^5
 *
 *
 *
 * Follow up: Could you solve it with time complexity O(height of tree)?
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
  TreeNode* deleteNode(TreeNode* root, int key) { return traversal(root, key); }

 private:
  TreeNode* traversal(TreeNode* node, int key) {
    if (!node) { return node; }
    if (node->val == key) {
      if (!node->left && !node->right) {
        node = nullptr;
      } else if (node->left && !node->right) {
        node = node->left;
      } else if (!node->left && node->right) {
        node = node->right;
      } else {
        TreeNode* right_leftmost = node->right;
        while (right_leftmost->left) { right_leftmost = right_leftmost->left; }
        right_leftmost->left = node->left;
        node = node->right;
      }
      return node;
    }
    if (node->val > key) {
      node->left = traversal(node->left, key);
    } else {
      node->right = traversal(node->right, key);
    }
    return node;
  }
};
// @lc code=end
