class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> index1;
        vector<int> index2;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==word1)
                index1.push_back(i);
            if(words[i]==word2)
                index2.push_back(i);
        }
        int minlen=INT_MAX;
        for(int i=0;i<index1.size();i++)
            for(int j=0;j<index2.size();j++)
                minlen=min(minlen,abs(index1[i]-index2[j]));
        return minlen;        
    }
};