class Solution {
public:
    struct myless {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> mymap;
        for (auto i : words) {
            mymap[i] ++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, myless> mypq;
        for (auto i : mymap) {
            mypq.push({i.second, i.first});
        }
        for (int i = 0; i < k; i ++) {
            res.push_back(mypq.top().second);
            mypq.pop();
        }
        
        return res;
    }
};