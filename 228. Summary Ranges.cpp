class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len=nums.size();
        vector<string> res;
        if(len==0)
            return res;
        if(len==1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start=0;
        int end=0;
        for(int i=1;i<len;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                end=i;
            }
            if(nums[i]!=nums[i-1]+1)
            {
                if(start==end)
                {
                    res.push_back(to_string(nums[i-1]));
                    start=i;
                    end=i;
                }
                else
                {
                    string tmp=to_string(nums[start])+"->"+to_string(nums[end]);
                    res.push_back(tmp);
                    start=i;
                    end=i;
                }
            }
        }
        if(start==end)
            {
                res.push_back(to_string(nums[end]));
            }
        else
            {
                string tmp=to_string(nums[start])+"->"+to_string(nums[end]);
                res.push_back(tmp);
            }
        return res;

    }
};