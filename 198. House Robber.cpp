class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.empty())
            return 0;
        else
        {
            int len=nums.size();
            if (len==1)
                return nums[0];
            else if (len==2)
                return max(nums[0],nums[1]);
            else 
            {
                int rob_tmp[len];
                rob_tmp[0]=nums[0];
                rob_tmp[1]=max(nums[0],nums[1]);
                for (int i=2;i<len;i++)
                    rob_tmp[i]=max(nums[i]+rob_tmp[i-2],rob_tmp[i-1]);
                return max(rob_tmp[len-1],rob_tmp[len-2]);
            }
                
        }

    }
};