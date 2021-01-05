class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        int res = 0;
        for (auto i : nums) {
            mymap[i] ++;
        }
        if (k < 0) {
            return 0;
        } else if (k == 0) {
            for (auto i : mymap) {
                if (i.second >= 2) {
                    res ++;
                }
            }
        } else {
            vector<int> elements;
            for (auto i : mymap) {
                elements.push_back(i.first);
            }
            for (int i = 0; i < elements.size(); i++) {
                int cur = elements[i];
                int target = cur + k;
                if (mymap.find(target) != mymap.end()) {
                    res ++;
                }
            }
        }
        return res;
    }
};