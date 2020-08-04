class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        int tmp_res=nums[0]+nums[1]+nums[2];
        std::sort(nums.begin(), nums.end());
        for(int i=0;i<len-2;i++)
        {
            int left=i+1;
            int right=len-1;
            while(left<right)
            {
                int tmp_sum=nums[i]+nums[left]+nums[right];
                if (tmp_sum==target)
                    return target;
                if(tmp_sum<target)
                    left++;
                if(tmp_sum>target)
                    right--;
                if(abs(tmp_sum-target)<abs(tmp_res-target))
                    tmp_res=tmp_sum;
            }
        }
        return tmp_res;

    }
};