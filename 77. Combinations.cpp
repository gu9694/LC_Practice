class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(n,1,k,tmp,res);
        return res;
    }
    
    void dfs(int n,int start,int k,vector<int>& tmp,vector<vector<int>>& res)
    {
        if(tmp.size()==k)
            res.push_back(tmp);
        
        for(int i=start;i<=n;i++)
        {
            tmp.push_back(i);
            dfs(n,i+1,k,tmp,res);
            tmp.pop_back();
        }
    }
};

//注意本题西i+1 只有要求返回全部有顺序排列才是start+1 line 18