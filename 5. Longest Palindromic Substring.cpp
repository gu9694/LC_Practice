// When string is blank?? initialization: start=0, pd_len=0;
// functions inside a function?? use auto to handle 
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        
        auto find_max=[&](int l, int r)
        {
            while(l>=0&&r<len&&s[l]==s[r])
            {
                l--;
                r++;
            }
            int max_l=r-l-1;
            return max_l;
        };
        
        int start=0;
        int pd_len=0;
        
        for (int i=0;i<len;i++)
        {
            int tmp=max(find_max(i,i+1),find_max(i,i));
            
            if(tmp>pd_len)
            {
                start=i-(tmp-1)/2;
                pd_len=tmp;
            }
        }
        return s.substr(start,pd_len);
    }
};

class Solution {
public:
    int find_max(int l,int r,int len, string s)
    {
        while(l>=0&&r<len&&s[l]==s[r])
            {
                l--;
                r++;
            }
            int max_l=r-l-1;
            return max_l;
    }
    string longestPalindrome(string s) {
        int len=s.length();
        
        auto find_max11=[&](int l, int r)
        {
            while(l>=0&&r<len&&s[l]==s[r])
            {
                l--;
                r++;
            }
            int max_l=r-l-1;
            return max_l;
        };
        
        int start=0;
        int pd_len=0;
        
        for (int i=0;i<len;i++)
        {
            int tmp=max(find_max(i,i+1,len,s),find_max(i,i,len,s));
            
            if(tmp>pd_len)
            {
                start=i-(tmp-1)/2;
                pd_len=tmp;
            }
        }
        return s.substr(start,pd_len);
    }
};
