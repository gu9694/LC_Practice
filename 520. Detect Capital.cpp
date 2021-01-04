class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if (len <= 1) {
            return true;
        } else {
            if (word[0] >= 97 && word[0] <= 122) { // lower case
                for (int i = 0; i < len; i++) {
                    if (word[i] <= 90) {
                        return false;
                    }
                }
            } else { // uppper case
                if (len == 2) {
                    return true;
                } else {
                    if (word[1] <= 90) {
                        for (int i = 2; i < len; i++) {
                            if (word[i] >= 97) {
                                return false;
                            }
                        }
                    } else {
                        for (int i = 2; i < len; i++) {
                            if (word[i] <= 90) {
                                return false;
                            }
                        }
                    }
                }

            }
        }
        return true;
    }
};