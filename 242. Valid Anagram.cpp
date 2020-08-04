class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> maps;
        unordered_map<char,int> mapt;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
            maps[s[i]]++;
        for(int j=0;j<t.length();j++)
            mapt[t[j]]++;
        return maps==mapt;
    }
};

//map可以直接比较