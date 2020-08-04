class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len=nums.size();
        if(len<=3)
            return res;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<len-3;i++)
        {
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) 
                break;
		    if (nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target) 
                continue; 
		    if (i > 0 && nums[i] == nums[i-1]) 
                continue;
            for(j=i+1;j<len-2;j++)
            {
			    if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) 
                    break;
			    if (nums[i] + nums[j] + nums[len-2] + nums[len-1] < target) 
                    continue; 
			    if (j > i+1 && nums[j] == nums[j-1]) 
                    continue;
                else
                {
                    int left=j+1;
                    int right=len-1;
                    while(left<right)
                    {
                        int sum=nums[i]+nums[j]+nums[left]+nums[right];
                        if(sum==target)
                        {
                            vector<int> tmp {nums[i],nums[j],nums[left],nums[right]};
                            res.push_back(tmp);
                            while(left+1<right&&nums[left]==nums[left+1])
                            {
                                left++;
                            }
                            left++;
                            while(right-1>left&&nums[right]==nums[right-1])
                            {
                                right--;
                            }
                            right--;
                        }
                        else if(sum<target)
                            left++;
                        else if(sum>target)
                            right--;
                    }
                }
                
            }
        }
        return res;
                
    }
};

//i 1-len-3
//j i+1-len-2
//i,j的选择

//两个for循环break与continue的位置