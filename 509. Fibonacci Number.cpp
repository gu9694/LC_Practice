class Solution {
public:
    int fib(int N) {
        if(N==0)
            return 0;
        if(N==1)
            return 1;
        int f1=0;
        int f2=1;
        int res=1;
        while(N>=2)
        {
            res=f1+f2;
            f1=f2;
            f2=res;
            N--;
        }
        return res;
    }
};