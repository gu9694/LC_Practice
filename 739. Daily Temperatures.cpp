class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> myst;
        int len=T.size();
        vector<int> res(len);
        
        for(int i=0;i<len;i++)
        {
            while(myst.empty()==false&&T[i]>T[myst.top()])
            {
                res[myst.top()]=i-myst.top();
                myst.pop();
            }
            myst.push(i);
        }
        return res;

    }
};