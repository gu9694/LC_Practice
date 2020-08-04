class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        unordered_map<int,int> mymap;
        for(auto i:nums)
            mymap[i]++;
        for(auto j:mymap)
            if(j.second>1)
                return j.first;
        return 0;
        
    }
};