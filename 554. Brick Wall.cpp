class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    int leastBricks(vector<vector<int>>& wall) {
        int len = wall.size();
        unordered_map<int, int> mymap;
        if (len == 1) {
            return wall[0].size() > 1 ? 0 : 1;
        }
        for (int i = 0; i < len; i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size(); j ++) {
                sum += wall[i][j];
                mymap[sum] ++;
            }
        }
        vector<pair<int, int>> mypair;
        for (auto i : mymap) {
            mypair.push_back({i.first, i.second});
        }
        sort(mypair.begin(), mypair.end(), cmp);
        return mypair.size() > 1 ? len - mypair[1].second : len;
    }
};