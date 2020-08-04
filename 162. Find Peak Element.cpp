class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> res(nums.size()+2);
        res[0]=INT_MIN;
        res[nums.size()+1]=INT_MIN;
        for(int i=0;i<nums.size();i++)
            res[i+1]=nums[i];
        for(int i=1;i<nums.size()+1;i++)
            if(res[i]>res[i-1]&&res[i]>res[i+1])
                return i-1;
        return 0;
    }
};