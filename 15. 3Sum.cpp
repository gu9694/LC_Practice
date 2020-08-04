class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        vector<vector <int>> result;
        sort(nums.begin(),nums.end());//sort
        

            for (int i=0;i<len-2;i++)
            {
                if(nums[i]+nums[i+1]+nums[i+2]>0)
                    break;
                else if(nums[i]+nums[len-2]+nums[len-1]<0)
                    continue;
                else if(i>0&&nums[i]==nums[i-1])
                    continue;
                else
                {
                    int left=i+1;
                    int right=len-1;
                    int tmp=0;
                    while(left<right)
                    {
                        tmp=nums[i]+nums[left]+nums[right];
                        if (tmp==0)
                        {
                            vector<int> zerop {nums[i],nums[left],nums[right]};
                            result.push_back(zerop);
                            while (left+1<right&&nums[left]==nums[left+1])
                            {
                                left++;
                            }
                            left++;
                            while (right-1>left&&nums[right]==nums[right-1])
                            {
                                right--;
                            }
                            right--;
                        }
                        else if(tmp>0)
                        {
                            right--;
                        }
                        else//tmp<0
                        {
                            left++;
                            
                        }
                        
                    }
                }
            }
        
        return result;
    }
};
//一个固定下标+两个指针
//指针移动的规则
//break continue的使用
