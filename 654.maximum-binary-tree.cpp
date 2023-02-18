/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (84.55%)
 * Likes:    4477
 * Dislikes: 311
 * Total Accepted:    246.7K
 * Total Submissions: 291.4K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * You are given an integer array nums with no duplicates. A maximum binary
 * tree can be built recursively from nums using the following algorithm:
 *
 *
 * Create a root node whose value is the maximum value in nums.
 * Recursively build the left subtree on the subarray prefix to the left of the
 * maximum value.
 * Recursively build the right subtree on the subarray suffix to the right of
 * the maximum value.
 *
 *
 * Return the maximum binary tree built from nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,1,6,0,5]
 * Output: [6,3,5,null,2,0,null,null,1]
 * Explanation: The recursive calls are as follow:
 * - The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right
 * suffix is [0,5].
 * ⁠   - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix
 * is [2,1].
 * ⁠       - Empty array, so no child.
 * ⁠       - The largest value in [2,1] is 2. Left prefix is [] and right
 * suffix is [1].
 * ⁠           - Empty array, so no child.
 * ⁠           - Only one element, so child is a node with value 1.
 * ⁠   - The largest value in [0,5] is 5. Left prefix is [0] and right suffix
 * is [].
 * ⁠       - Only one element, so child is a node with value 0.
 * ⁠       - Empty array, so no child.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1]
 * Output: [3,null,2,null,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * All integers in nums are unique.
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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode* root = new TreeNode();
    helper(root, nums, 0, nums.size());
    return root;
  }

 private:
  void helper(TreeNode* node, const vector<int>& nums, int begin, int size) {
    if (size == 1) {
      node->val = nums.at(begin);
      return;
    }
    auto max_it = max_element(nums.begin() + begin, nums.begin() + begin + size);
    node->val = *max_it;
    
    int max_index = max_it - nums.begin();
    int left_begin = begin;
    int left_size = max_index - begin;
    int right_begin = max_index + 1;
    int right_size = size - left_size - 1;

    if (left_size) {
      TreeNode* left_node = new TreeNode();
      node->left = left_node;
      helper(node->left, nums, left_begin, left_size);
    }
    if (right_size) {
      TreeNode* right_node = new TreeNode();
      node->right = right_node;
      helper(node->right, nums, right_begin, right_size);
    }
  }
};
// @lc code=end
