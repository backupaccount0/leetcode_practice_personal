/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) { return 0; }
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<vector<int>> neighbours_rel_pos{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        vector<int> cur_pos{i, j};
        queue<vector<int>> q;
        q.push(cur_pos);
        if (grid[i][j] == '1' && !visited[i][j]) {
          for (auto rel_pos : neighbours_rel_pos) {
            if (grid[i + rel_pos[0]][j + rel_pos[1]] == '1' && !visited[i + rel_pos[0]][j + rel_pos[1]]) {
              q.push(cur_pos);
            }
          }
        }
      }
    }
  }
};
// @lc code=end
