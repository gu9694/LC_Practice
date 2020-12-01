class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        unordered_map<int, int> mymap;
        vector<int> res;
        if (k == 0)
            return {};
        for(int i = 0; i <= k; i++ ) {
            int shortnum = i;
            int longnum = k - i;
            int len = shorter * shortnum + longer * longnum;
            if (mymap.find(len) == mymap.end()) {
                mymap[len] = 1;
                res.push_back(len);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};