class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(s,0,tmp,res);
        return res;
    }
    
    void dfs(string s, int start,vector<string>& tmp, vector<vector<string>>& res)
    {
        int len=s.length();
        if(start==len)
                res.push_back(tmp);
        for(int i=start;i<len;i++)
        {
            string cur=s.substr(start,i-start+1);
            if(judge(cur)==true)
            {
                tmp.push_back(cur);
                dfs(s,i+1,tmp,res);
                tmp.pop_back();
            }
        }
    }
        
    bool judge(string s){
        int len=s.length();
        if(len==1)
            return true;
        int left=0;
        int right=len-1;
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};