class Solution {
public:
    string addBinary(string a, string b) {
        int lena=a.length();
        int lenb=b.length();
        int len = max(lena,lenb);
        string res="";
        while(lena<len)
        {
            a='0'+a;
            lena++;
        }
        while(lenb<len)
        {
            b='0'+b;
            lenb++;
        }
        int carry=0;
        for(int i=len-1;i>=0;i--)
        {
            int sum=stoi(a.substr(i,1))+stoi(b.substr(i,1))+carry;
            if(sum==0)
            {
                res='0'+res;
                carry=0;
            }
            if(sum==1)
            {
                res='1'+res;
                carry=0;
            }
            if(sum==2)
            {
                res='0'+res;
                carry=1;
            }
            if(sum==3)
            {
                res='1'+res;
                carry=1;
            }
        }
        if (carry==1)
            res='1'+res;
        return res;

    }
};