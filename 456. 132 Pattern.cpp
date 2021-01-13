class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return false;
        } else if (len == 3) {
            return nums[0] < nums [2] & nums[2] < nums[1];
        } else {
            bool res = false;
            int middle = INT_MIN;
            int len = nums.size();
            stack<int> myst;
            for (int i = len - 1; i >= 0; i --) {
                if (nums[i] < middle) {
                    return true;
                }
                while(myst.empty() == false && myst.top() < nums[i]) {
                    middle = myst.top();
                    myst.pop();
                }
                myst.push(nums[i]);
            }
        }
        return false;
    }
};