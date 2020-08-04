class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()==true)
            return {};
        
        vector<vector<char>> d(10);
        d[0]={};
        d[1]={};
        d[2]={'a','b','c'};
        d[3]={'d','e','f'};
        d[4]={'g','h','i'};
        d[5]={'j','k','l'};
        d[6]={'m','n','o'};
        d[7]={'p','q','r','s'};
        d[8]={'t','u','v'};
        d[9]={'w','x','y','z'};
        
        string tmp;
        vector<string> res;
        dfs(digits,d,0,tmp,res);
        

        return res;
    }
private:
    void dfs(string& digits,vector<vector<char>> &d,int l, string &tmp, vector<string>& res)
    {
        int len=digits.length();
        if(l==len)
        {
            res.push_back(tmp);
            return;
        }
        for(char c: d[digits[l]-'0'])
        {
            tmp.push_back(c);
            dfs(digits,d,l+1,tmp,res);
            tmp.pop_back();
        }
    }

};