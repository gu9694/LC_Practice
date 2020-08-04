class Solution {
public:
    int calculate(string s) {
        int len=s.length();
        char op='+';
        long long int num=0;
        stack<long long int> tmp;
        for(int i=0;i<len;i++)
        {
            if(s[i]-'0'>=0)
            {
                num=num*10+s[i]-'0';
            }
            if ((s[i]<'0' && s[i]!=' ')||i==len-1 )
            {
                if(op=='+')
                    tmp.push(num);
                if(op=='-')
                    tmp.push(-num);
                if(op=='*')
                {
                    int a=tmp.top();
                    tmp.pop();
                    a=a*num;
                    tmp.push(a);
                }
                if(op=='/')
                {
                    int a=tmp.top();
                    tmp.pop();
                    a=a/num;
                    tmp.push(a);
                }
                op=s[i];
                num=0;
            }
        }
        long long int res=0;
        while(tmp.empty()==false)
        {
            res+=tmp.top();
            tmp.pop();
        }
        return res;
    }
};

//字节跳动一面就栽在这里！！
//line14 注意判断条件
//s[i]是当前的运算符号 用来更新op
//op + 把当前元素入栈 相当于+3........
//op * 当前元素乘栈顶元素并更新栈顶元素 