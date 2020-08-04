class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len=nums.size();
        int left=0;
        int right=0;
        int minlen=INT_MAX;
        int sum=0;
        if(nums.size()==0)
            return 0;
        int max=0;
        for(auto i: nums)
            max+=i;
        if(max==s)
            return len;
        if(max<s)
            return 0;
        while(left<len)
        {
            if(sum<s&&right<len)
            {
                sum+=nums[right];
                right++;
            }
            else
            {
                if(sum>=s)
                {
                    minlen=min(minlen,right-left);
                }
                sum-=nums[left];
                left++;
            }
        }
        return minlen;
    }
};