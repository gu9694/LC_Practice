class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        if(len3!=len1+len2)
            return false;
        bool dp[len1+1][len2+1];
        for(int i=0;i<=len1;i++)
            for(int j=0;j<=len2;j++)
                dp[i][j]=false;
        
        dp[0][0]=true;
        for(int i=1;i<=len1;i++)
            dp[i][0]=(s1[i-1]==s3[i-1]&&dp[i-1][0]==true);
        for(int j=1;j<=len2;j++)
            dp[0][j]=(s2[j-1]==s3[j-1]&&dp[0][j-1]==true);
        
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1]==s3[i+j-1]&&dp[i-1][j]==true)
                    dp[i][j]=true;
                else if(s2[j-1]==s3[i+j-1]&&dp[i][j-1]==true)
                    dp[i][j]=true;
            }
        return dp[len1][len2];
    }
};

//典型的双字符串dp
//1 要理解dp[i[j]的含义
//2 边界条件的的初始化
//3 注意下表的转换 比如dp[len1+1][len2+1] 