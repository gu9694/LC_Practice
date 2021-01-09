class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int start = 0;
        vector<string>  v1;
        for (int i = 0; i < s.length(); i ++)
        {
            if (s[i] == ' ') {
                v1.push_back(s.substr(start, i - start));
                start = i + 1;
            }
            if ( i == s.length() - 1) {
                v1.push_back(s.substr(start, i - start + 1));
            }
        }
        for (int i = v1.size() - 1; i>= 0; i --) {
            reverse(v1[i].begin(), v1[i].end());
            res = v1[i] + res;
            if (i > 0) {
                res = ' ' + res;
            }
        }
        return res;
    }
};