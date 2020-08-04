class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
            return res;
        else if(numRows==1)
        {
            res.push_back({1});
            return res;
        }
        else if(numRows==2)
        {
            res.push_back({1});
            res.push_back({1,1});
            return res;
        }
        else//n>2
        {
            res.push_back({1});
            res.push_back({1,1});
            vector<int> tmp(2,1);
            for(int i=3;i<=numRows;i++)
            {
                vector<int> cur (i);
                cur[0]=1;
                cur[i-1]=1;
                for(int j=1;j<i-1;j++)
                    cur[j]=tmp[j-1]+tmp[j];
                tmp=cur;
                res.push_back(cur);
            }
        }
        return res;
    }
};