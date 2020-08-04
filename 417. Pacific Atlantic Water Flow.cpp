class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int row=matrix.size();
    	int col=matrix[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> p(row,vector<bool>(col,false));
		vector<vector<bool>> a(row,vector<bool>(col,false));

		for(int i=0;i<row;i++)
		{
			dfs(matrix,p,INT_MIN,i,0);
			dfs(matrix,a,INT_MIN,i,col-1);
		}

		for(int j=0;j<col;j++)
		{
			dfs(matrix,p,INT_MIN,0,j);
			dfs(matrix,a,INT_MIN,row-1,j);
		}
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(p[i][j]&&a[i][j])
					res.push_back({i,j});
		return res;
    }

    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>& ocean, int pre, int i, int j)
    {
    	int row=matrix.size();
    	int col=matrix[0].size();
    	if(i<0||j<0||i>=row||j>=col||matrix[i][j]<pre||ocean[i][j])
    		return;
    	ocean[i][j]=true;
    	dfs(matrix,ocean,matrix[i][j],i+1,j);
    	dfs(matrix,ocean,matrix[i][j],i-1,j);
    	dfs(matrix,ocean,matrix[i][j],i,j+1);
    	dfs(matrix,ocean,matrix[i][j],i,j-1);
    	return;
    }
};