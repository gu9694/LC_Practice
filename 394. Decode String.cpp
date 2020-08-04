class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> num;
        stack<string> tmp;
        int len=s.size();
        if(len==0)
            return res;
        for(int i=0;i<len;i++)
        {
            if(isdigit(s[i]))
            {
                int start=i;
                while(i<len&&isdigit(s[i]))
                    i++;
                int n=stoi(s.substr(start,i-start));
                num.push(n);
                tmp.push(res);
                res="";
            }
            else if(s[i]=='[')
                continue;
            else if(s[i]==']')
            {
                int n=num.top();
                
                string k=res;
                for(int i=0;i<n-1;i++)
                    res+=k;                
                num.pop();
                res=tmp.top()+res;
                tmp.pop();
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;

 
    }
};

//isdigit函数与stoi函数的结合在string中取出int 最后指针停在最后一位数字的后一位
//理解进栈出栈的关系！！