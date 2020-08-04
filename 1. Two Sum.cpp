class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> mymap;
        vector <int> res;
        for (int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]=i;
        }
        
        for (int i=0;i<nums.size();i++)
        {
            int result= target-nums[i];
            if (mymap.find(result)!=mymap.end()&&mymap[result]!=i)
            {
                res.push_back(i);
                res.push_back(mymap[result]);
                
                return res;
            }
        }
    
        return res;
    }
};
//unordered_map
//index->value
//map[index]=value
