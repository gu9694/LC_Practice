class Solution {
public:
    int numDecodings(string s) {
        int len=s.length();
        if(s.empty()==true)
            return 0;
        if(s[0]=='0')
            return 0;
        int dp[len+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=len;i++)
        {
            if(s[i-1]!='0')
                dp[i]=dp[i-1];
            if(i>=2&&s.substr(i-2,2)>="10"&&s.substr(i-2,2)<="26")
                dp[i]+=dp[i-2];
        }
        return dp[len];
    }
};

//dp[0]=1
//s.substr(i-2,2)>="10"&&s.substr(i-2,2)<="26"
//全部初始化为0 这样万一在哪里卡住了后面返回的也是0