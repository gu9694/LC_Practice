class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len= nums.size();
        vector<int> res(len);
        res[0]=1;
        
        // calculate left
        for(int i=1;i<len;i++)
        {
            res[i]=res[i-1]*nums[i-1];
        }
        
        //calculate right
        int right=1;
        for(int j=len-1;j>=0;j--)
        {
            res[j]=res[j]*right;
            right=right*nums[j];
        }
        return res;
    }
};