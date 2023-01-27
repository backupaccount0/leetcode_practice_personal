/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        if (length > 0) {
            int left_index = 0;
            int right_index = length-1;
            while (left_index < right_index) {
                char temp = s[left_index];
                s[left_index] = s[right_index];
                s[right_index] = temp;
                left_index++;
                right_index--;
            }

        }
    }

    // void reverseString(vector<char>& s) {
    //     vector<char> s_reverse;
    //     int length = s.size();
    //     for (int i = 0; i < length; ++i) {
    //           s_reverse.push_back(s[length-i-1]);
    //     }
    //     s = s_reverse;
    // }
};
// @lc code=end
