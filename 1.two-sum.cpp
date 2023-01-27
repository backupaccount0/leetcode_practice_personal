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
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(target - nums[i]) != map.end()) { return vector<int>{i, map[target - nums[i]]}; }
      map.insert(pair<int, int>(nums[i], i));
    }
    return {};
  }
};
// @lc code=end
