class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len=intervals.size();
        if(len==0)
            return 0;
        if(len==1)
            return 1;
        priority_queue <int,vector<int>,greater<int> > pq;
        
        sort(intervals.begin(),intervals.end());
        
        int num=0;
        
        for(int i=0;i<len;i++)
        {
            while(pq.size()&&intervals[i][0]>=pq.top())
            {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            int curnum=pq.size();
            num=max(num,curnum);                    
        }
        
        return num;

        
    }
};

//priority_queue的使用 一定要把三个参量都写全
//pq中存放的是正在使用的会议室的结束时间
//如果下一个会议开始的时间晚于（大于）当前pq中会议室的结束时间，就可以吧当前会议室释放出来
//重载pq的第三个参数 重载()
//https://www.cnblogs.com/mengxiaoleng/p/11387601.html