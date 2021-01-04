class Solution {
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> myst;
        for (int i = 2 * nums.size() - 1; i >= 0; i --){
            while(myst.empty() == false && myst.top() <= nums[i % nums.size()]) {
                myst.pop();
            }
            res[i % nums.size()] = myst.empty() ? -1 : myst.top();
            myst.push(nums[i % nums.size()]);
        }
        return res;
    }
};

// 数组从后往前记录，结果数组的每一个元素两次更新