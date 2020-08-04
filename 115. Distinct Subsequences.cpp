class Solution {
public:
    int numDistinct(string s, string t) {
        int lent=t.length();
        int lens=s.length();
        int dp[lent+1][lens+1];
        for(int i=0;i<lent+1;i++)
            dp[i][0]=0;//s=0
        for(int i=0;i<lens+1;i++)
            dp[0][i]=1;//t=0 只有一种取法
        for(int i=1;i<lent+1;i++)
            for(int j=1;j<lens+1;j++)
            {
                dp[i][j]=dp[i][j-1];//t不变,至少应该和s-1相同
                if(s[j-1]==t[i-1])
                    dp[i][j]+=dp[i-1][j-1];
            }
        return dp[lent][lens];
    }
};