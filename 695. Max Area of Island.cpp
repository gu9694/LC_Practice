class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid.empty()==true)
            return 0;
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                if(grid[i][j]==1)
                {
                    int cur=0;
                    dfs(grid,i,j,m,n,cur);
                    res=max(res,cur);
                }
            }
        return res;
        
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j,int m, int n, int& cur)
    {
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0)
            return;
            cur++;
        grid[i][j]=0;
        dfs(grid,i-1,j,m,n,cur);
        dfs(grid,i+1,j,m,n,cur);
        dfs(grid,i,j-1,m,n,cur);
        dfs(grid,i,j+1,m,n,cur);            
    }
};

//一定要记住在dfs函数里把遍历过的点归零！！！！