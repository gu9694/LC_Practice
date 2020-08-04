class Solution {
public:
    int mySqrt(int x) {
        long long int i=0;
        for(i=0;i<x;i++)
        {
            if(i*i==x)
            {
                return i;
                break;
            }
            if(i*i<x&&(i+1)*(i+1)>x)
            {
                return i;
                break;
            }
        }
        return i;
    }
};