class Solution {
public:
    struct myless{
        bool operator()(pair<int,string> a, pair<int,string> b){
            return a.first<b.first||(a.first==b.first&&a.second>b.second);
        }
        
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> mymap;
        priority_queue<pair<int,string>,vector<pair<int,string>>,myless> mypq;
        int len=words.size();
        for(int i=0;i<len;i++)
        {
            mymap[words[i]]++;
        }
        for(auto i: mymap)
        {
            mypq.push(make_pair(i.second,i.first));
        }
        for(int i=1;i<=k;i++)
        {
            string tmp=mypq.top().second;
            mypq.pop();
            res.push_back(tmp);
        }
        return res;
        
    }
};

//先用hashmap存input
//然后用pq排hashmap
//pq中myless的定义：用结构体重载()，pq里定义myless居然不用加上()
//和973对比