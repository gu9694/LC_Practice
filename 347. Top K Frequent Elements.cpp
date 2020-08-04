class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> mypq;
        for(auto i:mymap)
        {
            mypq.push(make_pair(i.second,i.first));
        }
        vector<int> res;
        for(int i=1;i<=k;i++)
        {
            int cur=mypq.top().second;
            mypq.pop();
            res.push_back(cur);
        }
        return res;
    }
}

//又一map与pq联合使用的经典案例，先遍历，后排序