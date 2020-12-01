class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = len * (len + 1) / 2;
        int tmp = 0;
        for (auto i: nums)
            tmp += i;
        return sum - tmp;
    }
};