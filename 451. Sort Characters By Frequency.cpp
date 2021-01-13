class Solution {
public:
    struct myless {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char, int> mymap;
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            mymap[s[i]] ++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, myless> mypq;
        for (auto i : mymap) {
            mypq.push({i.first, i.second});
        }
        string res = "";
        while(mypq.empty() == false) {
            char cur = mypq.top().first;
            int times = mypq.top().second;
            for (int i = 0; i < times; i ++) {
                res.push_back(cur);
            }
            mypq.pop();
        }
        return res;
    }
};