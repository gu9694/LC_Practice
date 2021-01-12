class Solution {
public:
    void dfs(vector<vector<int>>& grid, int& res, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        res ++;
        dfs(grid, res, i + 1, j);
        dfs(grid, res, i - 1, j);
        dfs(grid, res, i, j + 1);
        dfs(grid, res, i, j - 1);
        return;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    dfs(grid, cur, i, j);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};