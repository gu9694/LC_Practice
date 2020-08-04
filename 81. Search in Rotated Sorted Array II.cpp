class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len=nums.size();
        int left=0;
        int right=len-1;
        while(left<=right)
        {
            if(nums[left]==target)
                return true;
            if(nums[right]==target)
                return true;
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return true;
            if(nums[left]<nums[mid])
            {
                if(nums[left]<target&&nums[mid]>=target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else if(nums[mid]<nums[right])
            {
                if(nums[mid]<target&&target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
            else
            {
                right--;
            }
        }
        return false;
    }
};

//要加上else right--这种情况：防止011234500 left=right的情况