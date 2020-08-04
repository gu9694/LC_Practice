class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        //int min_price=prices[0];
        int min_price=INT_MAX;
        int tmp_profit=0;
        for(int i=0;i<len;i++)
        {
            min_price=min(min_price,prices[i]);
            tmp_profit=max(tmp_profit,prices[i]-min_price);
        }
        return tmp_profit;

 

    }
};
//使用双数组
