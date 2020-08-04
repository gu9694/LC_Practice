class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res (amount+1,amount+1);
        res[0]=0;
        for(auto &x:coins)
        {
            for(int i=x;i<=amount;i++)
                res[i]=std::min(res[i],res[i-x]+1);
        }
        
        if(res[amount]>=amount+1)
            return -1;
        else
            return res[amount];
    }
};