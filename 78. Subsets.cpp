class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp;
        for(int i=0;i<=nums.size();i++)
		    dfs(res, tmp,i, nums, 0);
		return res;
	}

private:
	void dfs(vector<vector<int>>& res, vector<int>& tmp,int capacity, vector<int>& nums, int begin) {
        if(tmp.size()==capacity)
		    res.push_back(tmp);
		for (int i = begin; i<nums.size(); ++i) 
        {
			tmp.push_back(nums[i]);
			dfs(res, tmp,capacity, nums, i + 1);
			tmp.pop_back();
		}
	}
};