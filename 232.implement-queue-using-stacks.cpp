// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include "commoncppproblem232.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (61.41%)
 * Likes:    5528
 * Dislikes: 328
 * Total Accepted:    609.6K
 * Total Submissions: 970.4K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement a first in first out (FIFO) queue using only two stacks. The
 * implemented queue should support all the functions of a normal queue (push,
 * peek, pop, and empty).
 *
 * Implement the MyQueue class:
 *
 *
 * void push(int x) Pushes element x to the back of the queue.
 * int pop() Removes the element from the front of the queue and returns
 * it.
 * int peek() Returns the element at the front of the queue.
 * boolean empty() Returns true if the queue is empty, false otherwise.
 *
 *
 * Notes:
 *
 *
 * You must use only standard operations of a stack, which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, the stack may not be supported natively. You may
 * simulate a stack using a list or deque (double-ended queue) as long as you
 * use only a stack's standard operations.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * Output
 * [null, null, null, 1, 1, false]
 *
 * Explanation
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= x <= 9
 * At most 100 calls will be made to push, pop, peek, and empty.
 * All the calls to pop and peek are valid.
 *
 *
 *
 * Follow-up: Can you implement the queue such that each operation is amortized
 * O(1) time complexity? In other words, performing n operations will take
 * overall O(n) time even if one of those operations may take longer.
 *
 */

// @lc code=start
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { s.push(x); }

  int pop() {
    while (s.size() > 1) {
      int i = s.top();
      s.pop();
      s_prime.push(i);
    }
    int first = s.top();
    s.pop();
    while (!s_prime.empty()) {
      int i = s_prime.top();
      s_prime.pop();
      s.push(i);
    }
    return first;
  }

  int peek() {
    stack<int> s_prime(s);
    while (s_prime.size() > 1) { s_prime.pop(); }
    return s_prime.top();
  }

  bool empty() { return s.empty(); }

 private:
  stack<int> s;
  stack<int> s_prime;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
