class Solution {
public:
    static bool cmp(string a, string b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        } else {
            return a > b;
        }
    }

    bool ismatch(string s, string d) {
        int lens = s.length();
        int lend = d.length();
        int indexs = 0;
        int indexd = 0;
        while(indexs < lens && indexd < lend) {
            if(s[indexs] == d[indexd]) {
                indexs ++;
                indexd ++;
            } else {
                indexs ++;
            }
        }
        if (indexd == lend) {
            return true;
        } else {
            return false;
        }
    }

    string findLongestWord(string s, vector<string>& d) {
        int len = d.size();
        vector<string> res;
        for (int i = 0; i < d.size(); i++) {
            if (ismatch(s, d[i]) == true) {
                res.push_back(d[i]);
            }
        }
        sort(res.begin(), res.end(), cmp);
        if (res.size() == 0) {
            return "";
        }
        return res[res.size() - 1];
    }
};
