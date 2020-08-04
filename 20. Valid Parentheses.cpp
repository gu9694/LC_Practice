class Solution {
public:
    bool isValid(string s) {
        stack<char> myst;
        int len=s.length();
        if(len==0)
            return true;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                myst.push(s[i]);
            }
            else
            {
                if(myst.empty())
                    return false;
                char k=myst.top();
                myst.pop();
                if(k=='('&&s[i]!=')')
                    return false;
                if(k=='['&&s[i]!=']')
                    return false;
                if(k=='{'&&s[i]!='}')
                    return false;
            }

        }
            if(myst.empty()==false)
                return false;
            return true;

    }
};
//一定要注意return的位置，否则照死检查不出错误在哪里！！
