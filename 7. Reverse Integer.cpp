class Solution {
public:
    int reverse(int x) {
        long long int reverse=0;
        int current=0;
        if(x==0)
            return 0;
        while(x!=0)
        {
            current=x%10;
            reverse=10*reverse+current;
            x=x/10;
            if(reverse<INT_MIN || reverse>INT_MAX)
                return 0;
        }
        return reverse;
    }
};

//32-bit INT_MAX=2^31-1 INT_MIN=-2^31
//INT_MAX+1=INT_MIN

//-126%10=-6 向0取余数

//reverse算法对于所有整数成立