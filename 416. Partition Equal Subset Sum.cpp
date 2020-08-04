class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<2)
            return false;
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum&1)
            return false;
        int target=sum>>1;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++)
            for(int j=target;j>=nums[i];j--)
                dp[j]=dp[j]||dp[j-nums[i]];
        
        return dp[target];
    }
};