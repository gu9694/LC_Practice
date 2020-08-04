class Solution {
public:
    struct myless
    {
        bool operator()(pair<int,vector<int>> a, pair<int,vector<int>> b)
        {
            return a.first<b.first;
        }
        
    };
    static bool cmp(pair<int,vector<int>> a, pair<int,vector<int>> b)
    {
        return a.first<b.first;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len=points.size();
        vector<pair<int,vector<int>>> mymap;
        for(int i=0;i<len;i++)
        {
            int distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            mymap.push_back(make_pair(distance,points[i]));
        }
        //sort(mymap.begin(),mymap.end(),cmp);
        sort(mymap.begin(),mymap.end(),myless());
        //sort(mymap.begin(),mymap.end());//248ms+55.9mb
        vector<vector<int>> res;
        for(int j=0;j<K;j++)
            res.push_back(mymap[j].second);
        
        return res;
    }
};

//pair类型的定义 pair<int,vector<int>>
//制作pair类型 make_pair(a,b) 注意这里是圆括弧
//myless cmp在sort里的嵌套，和pair配合着用，不过很占用时间和内存