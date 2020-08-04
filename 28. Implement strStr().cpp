class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_hay=haystack.length();
        int len_nee=needle.length();
        int j;
        if(len_hay==0&&len_nee==0)
            return 0;
        if(len_hay==0)
            return -1;
        if(len_nee==0)
            return 0;
        for(int i=0;i<=len_hay-len_nee;i++)
        {
            if(haystack[i]!=needle[0])
                continue;
            if(haystack[i]==needle[0])
            {
                for(j=0;j<len_nee;j++)
                {
                    if(haystack[i+j]!=needle[j])
                        break;
                    if(haystack[i+j]==needle[j])
                        continue;
                }
                if (j==len_nee)
                    return i;
            }
        }
        return -1;
    }
};

//line 26: j==len_nee j会在len_nee终止 但是needle[j]只会判断到len_nee-1
