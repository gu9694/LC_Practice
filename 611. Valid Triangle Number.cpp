class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        if (len < 3) {
            return 0;
        } else if (len == 3) {
            return nums[0] + nums[1] > nums[2] ? 1 : 0;
        } else { // len > 3
            for (int i = len - 1; i >= 2; i --) {
                int left = 0;
                int right = i - 1;
                while(left < right) {
                    if (nums[left] + nums[right] > nums[i]) {
                        res += right - left;
                        right --;
                    } else {
                        left ++;
                    }
                }
            }
        }
        return res;
    }
};
