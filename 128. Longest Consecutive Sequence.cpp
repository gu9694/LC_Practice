class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=0;
        int res=1;
        if(nums.size()==0)
            return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            if(nums[i]==nums[i-1]+1)
            {
                end++;
            }
            else
            {
                res=max(res,end-start+1);
                start=i;
                end=i;
            }
        }
        return max(res,end-start+1);
            
    }
};