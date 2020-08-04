class Solution {
public:
    int findMin(vector<int>& nums) {
        int len=nums.size();
        if(len==1)
            return nums[0];
        if(len==2)
            return min(nums[0],nums[1]);
        int left=0;
        int right=len-1;
        while(left<right)
        {
            int mid=(right+left)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid;
        }
        return nums[right];
    }
};