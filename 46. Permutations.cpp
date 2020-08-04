class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<=1)
        {
            res.push_back(nums);
            return res;
        }
        vector<int> tmp;
        vector<bool> mark(nums.size(),false);
        dfs(nums,mark,tmp,res);
        return res;
	}
    void dfs(vector<int>& nums,vector<bool>& mark,vector<int>& tmp, vector<vector<int>>& res)
    {
        if(nums.size()==tmp.size())
        {
            res.push_back(tmp);
            tmp.clear();
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mark[i]==true)
                continue;
            if(mark[i]==false)
            {
                mark[i]=true;
                tmp.push_back(nums[i]);
                dfs(nums,mark,tmp,res);
                mark[i]=false;
                tmp.pop_back();
            }
        }
    }
};


//写辅助函数记得加引用
//经典深搜算法
//31-32行还是没怎么想通...........
