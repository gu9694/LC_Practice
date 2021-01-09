class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int len = nums.size();
        string res = "";
        if (len == 1) {
            return to_string(nums[0]);
        } else if (len == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        } else {
            res += to_string(nums[0]);
            res += "/(";
            for (int i = 1; i < len; i ++) {
                res += to_string(nums[i]);
                if (i == len - 1) {
                    res += ")";
                } else {
                    res += "/";
                }
            }
        }
        return res;
    }
};