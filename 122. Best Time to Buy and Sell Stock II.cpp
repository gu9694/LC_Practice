class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()==true)
            return 0;
        int len=prices.size();
        vector<int> rest(len);
        vector<int> hold(len);
        rest[0]=0;
        hold[0]=-prices[0];
        if(len<=1)
            return 0;
        for(int i=1;i<len;i++)
        {
            rest[i]=max(rest[i-1],hold[i-1]+prices[i]);
            hold[i]=max(hold[i-1],rest[i-1]-prices[i]);
        }
        return rest[len-1];
    }
};