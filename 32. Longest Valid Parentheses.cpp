class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myst;
        int len=s.length();
        int start=0;
        int res=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                myst.push(i);
            }
            else
            {
                if(myst.empty()==true)
                {
                    start=i+1;
                }
                else
                {
                    myst.pop();
                    if(myst.empty()==true)
                    {
                        res=max(res,i-start+1);
                    }
                    else
                    {
                        res=max(res,i-myst.top());
                    }
                }
            }
        }
        return res;
    }
};