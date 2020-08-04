class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int> res;
        int start=-1;
        int end=-1;
        int i;
        if(len==0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        if(target<nums[0]||target>nums[len-1])
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int left=0;
        int right=len-1;
        for(i=0;i<len;i++)
        {
            if(nums[i]==target)
            {
                start=i;
                break;
            }
            
        }
        if (i==len)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        end=find_end(nums,start);
        res.push_back(start);
        res.push_back(end);
        return res;
    }
    int find_end(vector<int>& nums, int start)
    {
        int len=nums.size();
        int res=0;
        for(int i=start;i<len;i++)
        {
            if(nums[i]==nums[start])
                res++;
            if(nums[i]!=nums[start])
                break;
        }
        return res+start-1;
    }
};