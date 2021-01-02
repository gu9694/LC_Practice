class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if (len < n) {
            return false;
        }
        vector<int> plant(len + 2, 0);
        for (int i = 1; i < plant.size() - 1; i++) {
            plant[i] = flowerbed[i-1];
        }
        int num = 0;
        for (int i = 1; i < plant.size() - 1; i++) {
            if (plant[i] == 0 && plant[i - 1] == 0 && plant[i + 1] == 0) {
                num ++;
                plant[i] = 1;
            }
        }
        return num >= n;
    }
};

// greedy