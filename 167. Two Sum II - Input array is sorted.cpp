class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        int left=0;
        int right=len-1;
        vector<int> res;
        while(left<right)
        {
            int l=numbers[left];
            int r=numbers[right];
            int sum=l+r;
            if(sum==target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            if(sum<target)
                left++;
            if(sum>target)
                right--;
        }
        return res;
    }
};