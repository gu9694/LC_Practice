class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return 0;
        } else {
            unordered_map<int, vector<int>> mymap;
            mymap[0].push_back(-1);
            int sum = 0;
            for (int i = 0; i < len; i ++) {
                if (nums[i] == 0) {
                    sum += -1;
                } else {
                    sum += 1;
                }
                mymap[sum].push_back(i);
            }
            vector<int> res;
            for (auto i : mymap) {
                if (i.second.size() >= 2) {
                    res.push_back(i.second[i.second.size() - 1] - i.second[0]);
                }
            }
            sort(res.begin(), res.end());
            return res.size() == 0 ? 0 : res[res.size() - 1];
        }
    }
};