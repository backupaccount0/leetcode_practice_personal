// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem206.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.67%)
 * Likes:    16340
 * Dislikes: 276
 * Total Accepted:    2.8M
 * Total Submissions: 3.9M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
  ListNode* reverseList(ListNode* head) {
    if (!head) { return head; }
    ListNode* cur_node = head;
    ListNode* pre_node = nullptr;
    ListNode* next_node;

    while (cur_node) {
      next_node = cur_node->next;
      cur_node->next = pre_node;
      pre_node = cur_node;
      cur_node = next_node;
    }

    return pre_node;
  }
};
// @lc code=end
