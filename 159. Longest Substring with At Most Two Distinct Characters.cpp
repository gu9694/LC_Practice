class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len=s.size();
        if(len<=2)
            return len;
        int res=0;
        int left=0;
        unordered_map<char,int> mymap;
        for(int i=0;i<len;i++)
        {
            mymap[s[i]]++;
            while(mymap.size()>2)
            {
                mymap[s[left]]--;
                if(mymap[s[left]]==0)
                {
                    mymap.erase(s[left]);
                }
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};
//动态规划 left指针一直向右移动 直到mymap中少于两个元素为止