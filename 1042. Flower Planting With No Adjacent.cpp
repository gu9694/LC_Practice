class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N,0);
        vector<vector<int>> graph(N);
        for (auto& road: paths)
        {
            graph[road[0]-1].push_back(road[1]-1);
            graph[road[1]-1].push_back(road[0]-1);
        }
        for(int i=0;i<N;i++)
        {
            unordered_set<int> neighbor;
            for(auto& nei: graph[i])
            {
                neighbor.insert(res[nei]);
            }
            
            for(int color=1;color<5;color++)
            {
                if(neighbor.count(color))
                    continue;
                if(neighbor.count(color)==0)
                {
                    res[i]=color;
                    break;
                }
            }
        }
        return res;
    }
};
//利用set保存当前访问node的邻居的涂色状况
//要找到与所有邻居都不相同的颜色