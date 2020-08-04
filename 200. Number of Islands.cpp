class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()==true)
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                res+=grid[i][j]-'0';
                dfs(grid,j,i,m,n);
            }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int j, int i, int m, int n)
    {
        if(j<0||i<0||j>=n||i>=m||grid[i][j]=='0')
            return;
        grid[i][j]='0';
        dfs(grid,j+1,i,m,n);
        dfs(grid,j-1,i,m,n);
        dfs(grid,j,i+1,m,n);
        dfs(grid,j,i-1,m,n);
    }
};