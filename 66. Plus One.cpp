class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int len= digits.size();
        for (int i= len-1;i>=0;i--)
        {
            int sum= digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
        }
        
        if (carry==1)
        {
            vector<int> new_num(len+1);
            new_num[0]=carry;
            for(int j=0;j<len;j++)
            {
                new_num[j+1]=digits[j];
            }
            return new_num;
                
        }
        else
        {
            return digits;
        }
    }
};

//数组从后向前加
//每一位的算法 carry以及新的digit的计算
