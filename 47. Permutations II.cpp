class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> mark(nums.size(),false);
        dfs(nums,res,tmp,mark);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, vector<bool>& mark)
    {
        if(tmp.size()==nums.size())
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(mark[i]==true)
                continue;
            else
            {
                if(i>0 && nums[i]==nums[i-1] && mark[i-1]==true)
                    continue;
                else
                {
                    mark[i]=true;
                    tmp.push_back(nums[i]);
                    dfs(nums,res,tmp,mark);
                    mark[i]=false;
                    tmp.pop_back();
                }

            }
                
        }
    }
};
//注意限定条件 line26