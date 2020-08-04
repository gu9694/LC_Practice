class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        return nums[len-k];

    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        priority_queue <int,vector<int>,less<int> > pq(nums.begin(),nums.end());
       // for(int i=0;i<len;i++)
            //pq.push(nums[i]);
        for(int j=1;j<k;j++)
            pq.pop();
        return pq.top();

    }
};

//两种方法 注意pq的greater与less