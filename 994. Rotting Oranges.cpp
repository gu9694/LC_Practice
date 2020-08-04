class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    q.push(make_pair(i,j));//push i j pair
            }
        vector<int> dirs={1,0,-1,0,1};
        int days=0;
        if(fresh==0)
            return 0;
        if(q.empty()==true&&fresh!=0)
            return -1;
        while(q.empty()==false&&fresh>0)
        {
            int size=q.size();
            while(size>0)//chai
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                size--;
                for(int i=0;i<4;i++)
                {
                    int dx=x+dirs[i];
                    int dy=y+dirs[i+1];
                    if(dx<0||dx>=m||dy<0||dy>=n||grid[dx][dy]!=1)
                        continue;
                    fresh--;
                    grid[dx][dy]=2;
                    q.push(make_pair(dx,dy));
                }
            }
            days++;
        }
        return fresh==0? days:-1;
    }
};

//为什么bfs要用queue作为数据结构？
//通过pop front调用队首的元素进行处理，然后将新的元素通过push加到队尾上