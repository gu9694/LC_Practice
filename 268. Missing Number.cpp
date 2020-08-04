class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len=nums.size();
        int sum=nums.size()*(nums.size()+1)/2;
        int res=sum;
        for(auto i:nums)
            res-=i;
        return res;
    }
};