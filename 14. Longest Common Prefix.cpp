class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int len=strs.size();
        if(len==0)
            return res;
        if(len==1)
        {
            res=strs[0];
            return res;
        }
        int len_f=strs[0].size();
        for(int i=0;i<len_f;i++)
        {
            for(int j=1;j<len;j++)
            {
                if(i>=strs[j].size()||strs[0][i]!=strs[j][i])
                {
                    return res;
                }
                else
                    continue;

            }
            res.push_back(strs[0][i]);
        }
        return res;


    }
};