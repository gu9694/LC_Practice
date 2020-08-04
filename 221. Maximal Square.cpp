class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()==true)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        //int dp[m][n];
        //for(int i=0;i<m;i++)
            //for(int j=0;j<n;j++)
                //dp[i][j]=0;
        vector<vector<int>> dp(m,vector<int> (n,0));
        int res=0;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    if(matrix[i][j]=='0')
                        dp[i][j]=0;
                    else
                    {
                        dp[i][j]=1;
                        res=std::max(res,dp[i][j]);
                    }

                    
                }
                else
                {
                    if(matrix[i][j]=='1')
                    {
                        dp[i][j]=std::min(dp[i-1][j],std::min(dp[i][j-1],dp[i-1][j-1]))+1;
                        res=std::max(res,dp[i][j]);
                    }                        
                    else 
                        dp[i][j]=0;
                }
            }
        return res*res;
    }
};

//好像int内存比vector少
