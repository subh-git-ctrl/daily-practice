1class Solution {
2public:
3    bool check(int r, int c, vector<vector<int>>& grid,
4               vector<vector<int>>& directions, int n) {
5        int curr = grid[r][c];
6        if (curr == n * n - 1) {
7            return true;
8        }
9
10        for (auto& dir : directions) {
11            int i_new = r + dir[0];
12            int j_new = c + dir[1];
13
14            if (i_new >= 0 && i_new < n && j_new >= 0 && j_new < n &&
15                grid[i_new][j_new] == (1 + curr)) {
16                if (check(i_new, j_new, grid, directions, n))
17                    return true;
18                else return false;
19            }
20            
21        }
22        return false;
23    }
24    bool checkValidGrid(vector<vector<int>>& grid) {
25        vector<vector<int>> directions = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
26                                          {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
27        int n = grid.size();
28        if (grid[0][0] != 0)
29            return false;
30        return check(0, 0, grid, directions, n);
31    }
32};