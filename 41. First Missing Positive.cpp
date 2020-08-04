class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
            return 1;
        sort(nums.begin(),nums.end());
        unordered_set<int> myset;
        for(auto i:nums)
        {
            if(i>0)
                myset.emplace(i);
        }
        if(nums[nums.size()-1]<=0)
            return 1;
        int target=1;
        while(myset.find(target)!=myset.end())
            target++;
        return target;
    }
};