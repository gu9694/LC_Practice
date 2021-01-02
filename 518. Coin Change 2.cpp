class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> res(amount + 1, 0);
        res[0] = 1;
        for (auto coin : coins) {
            for (int i = coin; i <= amount; i++) {
                res[i] += res[i - coin];
            }
        }
        return res[amount];
    }
};