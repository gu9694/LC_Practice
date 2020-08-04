class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num=gas.size();
        for(int i=0;i<num;i++)
        {
            if (judge(gas,cost,i,num)==true)
            {
                return i;
            }
        }
        return -1;
    }
    bool judge(vector<int>& gas, vector<int>& cost, int i,int num)
    {
        int curindex=i;
        int curgas=0+gas[curindex];
        while(curgas>=cost[curindex%num]&&curindex<=i+num)
        {
            curgas=curgas-cost[curindex%num];
            curindex++;
            curgas=curgas+gas[curindex%num];
        }
        if(curindex>=i+num)
            return true;
        return false;
    }
};