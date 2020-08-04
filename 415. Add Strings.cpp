class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()==0)
            return num2;
        if(num2.size()==0)
            return num1;
        if(num1.length()<num2.length())
            swap(num1,num2);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int flag=0;
        string res;
        int len1=num1.length();
        int len2=num2.length();
        for(int i=0;i<len2;i++)
        {
            int tmp1=num1[i]-'0';
            int tmp2=num2[i]-'0';
            int cur=tmp1+tmp2+flag;
            res+=to_string(cur%10);
            flag=cur/10;
        }
        for(int i=len2;i<len1;i++)
        {
            int tmp1=num1[i]-'0';
            int cur=tmp1+flag;
            res+=to_string(cur%10);
            flag=cur/10;
        }
        if(flag==1)
            res+="1";
        reverse(res.begin(),res.end());
        return res;
    }
};