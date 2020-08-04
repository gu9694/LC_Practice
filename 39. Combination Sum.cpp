class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates,0,target,tmp,res);
        return res;
    }
    
    void dfs(vector<int>& candidates, int start, int remain, vector<int>& tmp, vector<vector<int>>&res)
    {
        if(remain==0)
        {
            res.push_back(tmp);
            //tmp.clear();
            return;
        }
        if(remain<0)
            return;
        for(int i=start; i<candidates.size()&&remain>=candidates[i];i++)
        {
            if(remain>=candidates[i])
            {
                tmp.push_back(candidates[i]);
                dfs(candidates,i,remain-candidates[i],tmp,res);
                tmp.pop_back();
            }
        }
        return;
        
    }
};

//16行 tmp.clear(千万不能加 这是为啥？？？？)
