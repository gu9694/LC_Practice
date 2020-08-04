class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        for(int i=1;i<=k;i++)
            helper(nums);
    }
    
    void helper(vector<int>& nums)
    {
        int len=nums.size();
        int last=nums[len-1];
        int pre=nums[0];
        int tmp;
        for(int i=1;i<len;i++)
        {
            tmp=nums[i];
            nums[i]=pre;
            pre=tmp;
        }
        nums[0]=last;
        return;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        for(int i=1;i<=nums.size()-k;i++)
        {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
        return;
    }
};

//vector erase函数的使用 输入的是元素的迭代器