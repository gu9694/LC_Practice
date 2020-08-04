class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        int len=s.length();
        if(len==0||len==1)
            return true;
        for(int i=0;i<len;i++)
        {
            if(isalpha(s[i])||isdigit(s[i]))
            {
                res.push_back(s[i]);
            }
        }
        int lenres=res.length();
        if(lenres==0||lenres==1)
            return true;
        int left=0;
        int right=lenres-1;
        while(left<=right)
        {
            if(toupper(res[left])!=toupper(res[right]))
            {
                return false;
                break;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};