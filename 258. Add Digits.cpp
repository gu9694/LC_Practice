class Solution {
public:

    int addDigits(int num) {
        auto add=[&num](int num)
        {
                int res=0;
                while(num!=0)
            {
                res+=num%10;
                num=num/10;
            }
                return res;
         };
        
        int res=add(num);
        if(num<10)
            return num;
        else
        {
            while(res>=10)
            {
                res=add(res);
            }
        }
        return res;
    }
};

//lambda函数的用法