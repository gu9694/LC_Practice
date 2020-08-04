class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> newnums;
        vector<int> res(nums.size());
        if(nums.size()==0)
            return {};
        if(nums.size()==1)
            return {0};
        newnums.push_back(nums[nums.size()-1]);
        res[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            int left=0;
            int right=newnums.size();
            while(left<right)
            {
                int mid=(right+left)/2;
                if(nums[i]<=newnums[mid])
                    right=mid;
                else
                    left=mid+1;
            }
            res[i]=right;
            newnums.insert(newnums.begin()+right,nums[i]);
        }
        return res;
    }
};

//newnums保存当前状态下已经搜索过的值 并不断用二分搜索插入