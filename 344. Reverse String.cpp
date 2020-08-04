class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        char tmp;
        if(len==0||len==1)
            {}
        else if(len%2==0)
        {
            for(int i=0;i<len/2;i++)
            {
                tmp=s[i];
                s[i]=s[len-1-i];
                s[len-1-i]=tmp;
            }
        }
        else if (len%2==1)
        {
            for(int i=0;i<(len-1)/2;i++)
            {
                tmp=s[i];
                s[i]=s[len-1-i];
                s[len-1-i]=tmp;
            }
        }

    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        char tmp;
            for(int i=0;i<len/2;i++)
            {
                tmp=s[i];
                s[i]=s[len-1-i];
                s[len-1-i]=tmp;
            }

    }
};

//奇数与偶数情况相同，不用写那么麻烦