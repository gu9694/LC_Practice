class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        if(len1==0||len2==0||num1=="0"||num2=="0")
            return "0";
        vector<int>  res(len1+len2);
        for(int i=len1-1;i>=0;i--)
            for(int j=len2-1;j>=0;j--)
            {
                int n1=num1[i]-'0';
                int n2=num2[j]-'0';
                int low=i+j+1;
                int high=i+j;
                int cur=n1*n2+res[low];
                res[low]=cur%10;
                res[high]+=cur/10;
            }
        string s;
        for (int val : res) 
        {
            if (!s.empty()||val!= 0) s.push_back(val+'0');
        }
        return s;

    
    }
};

//注意乘法的基本原理 i位与j位相乘最多i+j位 num[i]与num[j]相乘 高位在i+j 低位在i+j+1 千万别弄反
//好像只能j--下来 不能加上去