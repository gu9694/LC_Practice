class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        dp[0][0]=grid[0][0];
        //m
        for (int i=1;i<m;i++ )
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        //n
        for (int j=1;j<n;j++)
        {
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        //middle
        for (int p=1;p<m;p++)
            for (int q=1;q<n;q++)
            {
                dp[p][q]=min(dp[p-1][q],dp[p][q-1])+grid[p][q];
            }
        //result
        int res=dp[m-1][n-1];
        return res;
        
    }
};