class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int len = s.length();
        vector<vector<int>> res;
        if (len <= 2) {
            return res;
        } else {
            char cur = '*';
            int start = -1;
            int count = 0;
            for (int i = 0; i < len; i ++) {
                if (s[i] == cur) {
                    count ++;
                } else {
                    if (count >= 3) {
                        res.push_back({start, i - 1});
                    }
                    cur = s[i];
                    count = 1;
                    start = i;
                }
                if (i == len - 1) {
                    if (count >= 3) {
                        res.push_back({start, len - 1});
                    }
                }
            }
        }
        return res;
    }
};