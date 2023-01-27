// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (60.61%)
 * Likes:    8933
 * Dislikes: 348
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) { return head; }
    ListNode* pair_left = head;
    ListNode* pair_right = head->next;
    ListNode* next_pair_left;
    ListNode* next_pair_right;

    while (pair_right) {
      if (pair_left == head) { head = pair_right; }
      next_pair_left = pair_right->next;
      next_pair_left ? next_pair_right = next_pair_left->next : next_pair_right = nullptr;

      pair_right->next = pair_left;
      next_pair_right ? pair_left->next = next_pair_right : pair_left->next = next_pair_left;

      pair_left = next_pair_left;
      pair_right = next_pair_right;
    }
    return head;
  }
};
// @lc code=end
