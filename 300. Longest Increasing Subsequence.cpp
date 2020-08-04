class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> res(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                    res[i]=max(res[i],res[j]+1);
            }
        }
        return *max_element(res.begin(),res.end());
    }
};