class Solution {
public:
    int index(char c, string order)
    {
        int i=0;
        for(i=0;i<order.length();i++)
        {
            if(c==order[i])
                break;
        }
        return i;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int len=words.size();
        for(int i=1;i<len;i++)
        {
            if(compare(words[i-1],words[i],order)==false)
                return false;
        }
        return true;
    }
    bool compare(string word1, string word2, string order)
    {
        int len1=word1.length();
        int len2=word2.length();
        int len=min(len1,len2);
        for(int i=0;i<len;i++)
        {
            if(word1[i]==word2[i])
                continue;
            else if(word1[i]!=word2[i])
            {
                if(index(word1[i],order)<index(word2[i],order))
                    return true;
                else
                    return false;
            }
        }
        if(len1<=len2)
            return true;
        else
            return false;
    }

};