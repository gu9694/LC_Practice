class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        unordered_map<char,int> dict;
        int res=0;
        for(int i=0;i<len;i++)
        {
            dict[s[i]]=-1;
        }
        
        for(int left=0,right=0;right<len;right++)
        {
            left=max(left,dict[s[right]]+1);
            res=max(res,right-left+1);
            dict[s[right]]=right;
            
        }
        return res;
    }
};

//利用map的映射关系来记录每个字母最左边第一个的位置，虚拟位置为1
//右指针right固定，移动左指针
//left的位置单调不减少
