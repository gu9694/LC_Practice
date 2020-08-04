class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        if(len1==0||len2==0)
            return {};
        vector<int> res;
        unordered_map<int,int> mymap;
        for(int i=0;i<len1;i++)
            mymap[nums1[i]]=i;
        
        sort(nums2.begin(),nums2.end());
        if(mymap.find(nums2[0])!=mymap.end())
            res.push_back(nums2[0]);
        for(int i=1;i<len2;i++)
        {
            if(nums2[i]==nums2[i-1])
                continue;
            if(mymap.find(nums2[i])!=mymap.end())
                res.push_back(nums2[i]);
        }
        return res;
            
    }
};