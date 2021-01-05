class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length();
        int late = 0;
        int absent = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'A') {
                absent ++;
                late = 0;
            }
            if (s[i] == 'L') {
                late ++;
            }
            if (s[i] == 'P') {
                late = 0;
            }
            if (absent > 1 || late > 2) {
                return false;
            }
        }
        return true;
    }
};