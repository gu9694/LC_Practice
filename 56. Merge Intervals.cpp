class Solution {

public:
    struct cmp1
    {
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            return a[0]<b[0];
        }
    };

    static bool cmp(const vector<int>& a, const vector<int>& b){
        return (a[0]<b[0]);
    }
    

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len=intervals.size();
        if(len<=1)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp1());//
        sort(intervals.begin(),intervals.end(),cmp);//
        vector<vector <int>> res;
        
        int left=intervals[0][0];
        int right=intervals[0][1];

        for(int i=1;i<len;i++)
        {
            if(intervals[i][0]>right)
            {
                res.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
                
            else
            {
                right=max(intervals[i][1],right);
            }

        }
        
        res.push_back({left,right});
        return res;

    }
};

//利用struct重载()与直接通过函数写cmp的不同调用方法