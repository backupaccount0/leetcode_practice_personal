// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem19.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (40.14%)
 * Likes:    14462
 * Dislikes: 598
 * Total Accepted:    1.9M
 * Total Submissions: 4.6M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || n == 0) { return head; }
    ListNode* virtual_head = new ListNode(0, head);

    ListNode* left_pointer = virtual_head;
    ListNode* right_pointer = virtual_head;
    for (int i = 0; i < n; ++i) { right_pointer = right_pointer->next; }
    ListNode* tmp = nullptr;

    while (right_pointer) {
      if (!right_pointer->next) {
        tmp = left_pointer->next;
        left_pointer->next = left_pointer->next->next;
      }
      left_pointer = left_pointer->next;
      right_pointer = right_pointer->next;
    }
    if (tmp) { delete tmp; }
    head = virtual_head->next;
    delete virtual_head;
    return head;
  }
};
// @lc code=end
