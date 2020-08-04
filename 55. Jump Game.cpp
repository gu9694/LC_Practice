class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        if(len==1)
        {
            if(nums[0]==0)
                return true;
        }
        vector<int> mark(len);
        mark[0]=1;
        for(int i=0;i<len;i++)
        {
            if(mark[i]==1)
            {
                int dis=nums[i];
                for(int j=0;j<=dis&&i+j<len;j++)
                    mark[i+j]=1;
            }
            if(mark[i]==0)
                return false;
        }
        return mark[len-1];
    }
};