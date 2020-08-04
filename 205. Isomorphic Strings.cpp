class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> maps;
        unordered_map<char,char> mapt;
        for(int i=0;i<s.length();i++)
        {
            maps[s[i]]=t[i];
            mapt[t[i]]=s[i];
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=mapt[t[i]]||t[i]!=maps[s[i]])
                return false;
        }
        return true;
    }
};