class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        else if(x>=0 && x<10)
            return true;
        else
        {
            long long int reverse=0;
            int tmp=0;
            int ori=x;
            while(x!=0)
            {
                tmp=x%10;
                reverse=10*reverse+tmp;
                x=x/10;
            }
            if (reverse==ori)
                return true;
            else
                return false;
        }
    }
};

//计算相反数的方法
//long long int
