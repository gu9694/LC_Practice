class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if (len<=1)
            return 0;
        vector<int> hold(len);
        vector<int> sold(len);
        vector<int> rest(len);
        hold[0]=-prices[0];
        sold[0]=INT_MIN;
        rest[0]=0;
        for (int i=1;i<len;i++)
        {
            rest[i]=max(rest[i-1],sold[i-1]);
            hold[i]=max(hold[i-1],rest[i-1]-prices[i]);            
            sold[i]=hold[i-1]+prices[i];
        }
        return max(rest[len-1],sold[len-1]);
    }
};