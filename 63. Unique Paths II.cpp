class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int rows = obstacleGrid.size();
        const int cols = obstacleGrid[0].size();
        long long int dp[rows][cols];
        
        if(obstacleGrid[0][0]==0)
            dp[0][0] = 1;
        else
            return 0;
        
        for(int i = 1; i<cols; i++)
        {
            if(dp[0][i-1]==1 && obstacleGrid[0][i]==0)
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = 0;
            }
        }
        
        for(int i = 1; i<rows; i++)
        {
            if(dp[i-1][0]==1&&obstacleGrid[i][0]==0)
            {
                dp[i][0] = 1;
            }
            else 
                dp[i][0] = 0;
        }
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }   
                else
                    dp[i][j] = 0;
            }
        }
     
        return dp[rows-1][cols-1];     
    }  
};