class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len=graph.size();
        if(len==1||len==2)
            return true;
        vector<int> visited(len,-1);//-1 0 1 record whether visited and its group 
        
        for(int i=0;i<len;i++)
        {
            if(visited[i]==1)
                continue;
            if(visited[i]==-1)
            {
                queue<pair<int,int>> q;
                q.push(make_pair(i,0)); //give i value 0
                while(q.empty()==false)
                {
                    int node=q.front().first;
                    int group=q.front().second;
                    q.pop(); //always remember to pop
                    for(auto& next: graph[node]) //find nodes next to cur node
                    {
                        if(visited[next]!=-1) //if visited
                        {
                            if(visited[next]==group) // if belong to this group, directly return false
                                return false;
                        }
                        if(visited[next]==-1) // if unvisited 
                        {
                            visited[next]=1-group; //give its value reversing to cur node value
                            q.push(make_pair(next,1-group)); // push it into queue
                        }
                    }
                }
            }
        }
        return true;
    }
};

//图 深度优先搜索
//队列 queue 处理队头元素并pop 将新的元素加入队尾