class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mymap;
        unordered_set<int> myset;
        vector<int> res;
        for(auto i:nums)
            mymap[i]++;
        for(auto j:nums)
            if(mymap[j]>nums.size()/3)
                myset.insert(j);;
        for(auto k:myset)
            res.push_back(k);
        return res;
    }
};