class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int res=0;
            for(int j=0;j<i;j++)
                res=res+dp[j]*dp[i-1-j];
            dp[i]=res;
        }
        return dp[n];
    }
};