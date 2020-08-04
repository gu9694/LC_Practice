class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for(auto i: prerequisites)
            graph[i[0]].push_back(i[1]);
        
        vector<int> statue(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
            if(dfs(i,statue,graph)==true)
                return false;
        return true;
    }
    
    bool dfs(int i,vector<int>& statue,vector<vector<int>>& graph)
    {
        if(statue[i]==1)
            return true;
        if(statue[i]==2)
            return false;
        statue[i]=1;
        for(auto j: graph[i])
            if(dfs(j,statue,graph)==true)
                return true;
        statue[i]=2;
        return false;
    }
};



//DAG的DFS
//graph保存图以及direction statue保存访问状态 0 未访问 1 正访问 2 已访问
//注意dfs里statue的变化 和普通dfs不太一样