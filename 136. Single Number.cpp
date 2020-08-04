//Solution 1: Hash map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=-1;
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++)
            mymap[nums[i]]=0;
        for(int i=0;i<nums.size();i++)
            mymap[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {
            if(mymap[nums[i]]==1){
                a=nums[i];
                break;
            }
        }
    return a;
    }
};

//Solution 2: xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=nums[0];
        int res;
        for(int i=1;i<nums.size();i++)
        {
            a=a^nums[i];
        }
        return a;
    }
};
//xor 性质
//转换位二进制逐位xor 不同为1
//x^0=x 
//x^x=0
//交换律
//结合律