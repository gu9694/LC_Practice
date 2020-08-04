class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len=nums.size();
        vector <int> fmax(len);
        vector <int> fmin(len);
        
        fmax[0]=fmin[0]=nums[0];
        
        for(int i=1;i<len;i++)
        {
            fmax[i]=max(nums[i],max(nums[i]*fmax[i-1],nums[i]*fmin[i-1]));
            fmin[i]=min(nums[i],min(nums[i]*fmax[i-1],nums[i]*fmin[i-1]));
            
        }
        int a1=*max_element(fmax.begin(),fmax.end());

        return a1;

    }
};

//两个辅助数组
//取三个数最大值的方法
