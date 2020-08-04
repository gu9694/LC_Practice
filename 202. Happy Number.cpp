class Solution {
private:
    int square(int n)
    {
        int res=0;
        while(n!=0)
        {
            res=res+(n%10)*(n%10);
            n=n/10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        unordered_set<int> myset;
        while(n!=1 && myset.find(n)==myset.end())
              {
                  myset.insert(n);
                  n=square(n);
              }
        return n==1;
    }

};

//while条件的设置
//退出之后n就符合条件了