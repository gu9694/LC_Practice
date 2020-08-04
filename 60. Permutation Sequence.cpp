class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n,1);
        for(int i=1;i<fac.size();i++)
            fac[i]=i*fac[i-1];
        string num="123456789";
        string res;
        k--;//第0个
        for(int i=n;i>=1;i--)
        {
            int group_index=k/fac[i-1];
            k=k%fac[i-1];
            res.push_back(num[group_index]);
            num.erase(group_index,1);
        }
        return res;
    }
};

//erase(group_index,1)