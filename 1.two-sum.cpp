/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{};
        }
        std::unordered_map <int, int> hasp_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hasp_map.find(complement) == hasp_map.end()) {
                hasp_map[nums[i]] = i;
            } else {
                return vector<int>{i, hasp_map[complement]};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end
