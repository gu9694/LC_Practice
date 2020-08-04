class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto i: prerequisites)
            graph[i[0]].push_back(i[1]);
        vector<int> status(numCourses,0);
        vector<int> res;
        for(int i=0;i<numCourses;i++)
            if(dfs(graph,i,status,res))
                return {};
        return res;
    }
    
    
    bool dfs(vector<vector<int>>& graph, int i,vector<int>& status,
            vector<int>& res)
    {
        if(status[i]==1)//visiting
            return true;
        if(status[i]==2)//visited
            return false;
        status[i]=1;
        for(auto j:graph[i])
            if(dfs(graph,j,status,res)==true)
                return true;
        status[i]=2;
        res.push_back(i);
        return false;
    }
};