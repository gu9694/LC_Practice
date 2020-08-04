class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> tmp;
        vector<vector<int>> res;
        if(isPrime(n)==true)
            return res;
        dfs(n,2,tmp,res);
        return res;
    }
    
    void dfs(int n, int start, vector<int>& tmp, vector<vector<int>>& res)
    {
        for(int i=start;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                tmp.push_back(i);
                dfs(n/i,i,tmp,res);
                tmp.pop_back();
            }
        }
        if(tmp.size())
        {
            tmp.push_back(n);
            res.push_back(tmp);
            tmp.pop_back();
        }
        return;
    }
    
    
    
    bool isPrime(int n)
    {
        if(n==1||n==2||n==3)
            return true;
        if(n%2==0)
            return false;
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
    }
};

//line 20 注意dfs结束条件 是popback 不是clear