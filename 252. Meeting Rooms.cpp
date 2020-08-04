class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int len=intervals.size();
        if(len<=1)
            return true;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<len;i++)
            if(intervals[i][0]<intervals[i-1][1])
                return false;
        return true;
    }
};

//注意sort函数sort第一个值