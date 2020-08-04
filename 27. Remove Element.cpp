class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int num=std::distance(nums.begin(),std::remove(nums.begin(), nums.end(), val));
        return num;
    }
};
