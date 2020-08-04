class Solution {
public:
    int countPrimes(int n) {
        if(n<3)
            return 0;
        if(n==3)
            return 1;
        if(n==4)
            return 2;
            
        vector<int> judge(n,true);
        judge[0]=false;
        judge[1]=false;
        for(int i=2;i<sqrt(n);i++)
        {
            if(judge[i]==false)//not prime
                continue;
            if(judge[i]==true)//is prime
            {
                for(int j=i*2;j<n;j+=i)
                    judge[j]=false;
            }
        }
        return count(judge.begin(),judge.end(),true);
    }
};

//时间复杂度为线性