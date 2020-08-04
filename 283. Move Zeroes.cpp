class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int i=0;
        int j=0;
        for(i=0;i<len;i++)
        {
            if(nums[i]==0)
                continue;
            else if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        if(j==len)
            return;
        else
        {
            for(int k=j;k<len;k++)
                nums[k]=0;
        }
        return;
    }
};