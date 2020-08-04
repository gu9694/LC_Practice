class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int num=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                if(grid[i][j]==1)//
                {
                    if((i>=1&&grid[i-1][j]==0)||i==0)
                        num++;
                    if((i<m-1&&grid[i+1][j]==0||i==m-1))
                        num++;
                    if((j>=1&&grid[i][j-1]==0)||j==0)
                        num++;
                    if((j<n-1&&grid[i][j+1]==0)||j==n-1)
                        num++;
                }
            }
        return num;
    }
};