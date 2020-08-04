class Solution {
public:
    int firstUniqChar(string s) {
        int len=s.length();
        if(len==0)
            return -1;
        if(len==1)
            return 0;
        unordered_map<char,int> mymap;
        for(auto i:s)
            mymap[i]++;
        int index=0;
        while(index<=len-1)
        {
            if(mymap[s[index]]==1)
            {
                break; 
            }
            else
            {
                index++;
            }
        }
        if(index==len)
            return -1;
        else
            return index;
    }
};