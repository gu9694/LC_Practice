class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(auto i: timePoints) {
            int hour = stoi(i.substr(0, 2));
            int min = stoi(i.substr(3, 2));
            int cur = 60 * hour + min;
            time.push_back(cur);
        }
        sort(time.begin(), time.end());
        int res = INT_MAX;
        for (int i = 1; i < time.size(); i++) {
            res = min(res, time[i] - time[i - 1]);
        }
        res = min(24 * 60 - time[time.size() - 1] + time[0], res);
        return res;
    }
};