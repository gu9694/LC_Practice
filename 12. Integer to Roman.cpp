class Solution {
public:
    string intToRoman(int num) {
        string res="";
        int n_value[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string r_value[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<13;i++)
        {
            if(num==0)
                return res;
            while(num>=n_value[i])
            {
                num-=n_value[i];
                res+=r_value[i];
            }



        }
        return res;
        
        
    }
};
//while和do while的区别
//do while先无条件执行一次，再判断
//while先判断再执行

//先从大的开始减的思想

//map和双数组的选择
