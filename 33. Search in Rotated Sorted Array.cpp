class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0)
            return -1;
        int left=0;
        int right=len-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[left]==target)
                return left;
            if(nums[right]==target)
                return right;
            if(nums[mid]==target)
                return mid;
            if(nums[left]<=nums[mid])
            {
                if(target>nums[left]&&target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
            if(nums[right]>=nums[mid])
            {
                if(target>nums[mid]&&target<nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
                
        }
        return -1;
    }
};

//总是利用有序的一边进行二分查找