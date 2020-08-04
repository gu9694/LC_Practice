class Solution {
public:
    int calculate(string s) {
        int len=s.length();
        long long int res=0;
        int sign=1;
        stack<long long int> myst;
        if(len==0)
            return res;
        for(int i=0;i<len;i++)
        {
            if(s[i]-'0'>=0)
            {
                long long int num=0;
                while(i<len&&s[i]-'0'>=0)
                {
                    num=10*num+s[i]-'0';
                    i++;
                }
                    i--;
                    res+=sign*num;
            }

            if(s[i]=='+')
                sign=1;
            if(s[i]=='-')
                sign=-1;
            if(s[i]=='(')
            {
                myst.push(sign);
                myst.push(res);
                res=0;
                sign=1;
            }
            if(s[i]==')')
            {
                int pre_res=myst.top();
                myst.pop();
                int pre_op=myst.top();
                myst.pop();
                res=pre_res+pre_op*res;
            }
        }
        return res;
    }
};

//没有乘除法的优先级
//遇到括号就入栈 前面的结果res=0并保存在站里 重新计算括号内的res再与保存在栈里的之前的res相加
//o（n）的时间 从头到尾遍历即可