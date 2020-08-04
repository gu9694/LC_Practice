class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        if(nums.empty()==true)
            return res;
        for(int i=0;i<=nums.size();i++)
            dfs(nums,i,0,res, tmp);
        return res;
    }
    
    void dfs(vector<int>& nums, int k, int index, vector<vector<int>>& res
            ,vector<int>& tmp)
    {
        if(tmp.size()==k)
        {
            res.push_back(tmp);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums,k,i+1,res,tmp);
            tmp.pop_back();
            while (i+1 < nums.size() && nums[i] == nums[i+1]) 
                i++;
        }
        return;
    }
};

//for循环里加上while loop进行省略前进
//第一次遇到！！！！