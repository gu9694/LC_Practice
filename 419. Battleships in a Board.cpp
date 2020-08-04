class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0)
            return 0;
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int res=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='X'&&visited[i][j]==false)
                {
                     int row_d=0;
                     int col_d=0;
                     dfs(board,visited,i,j,row_d,col_d);
                     if(row_d==i||col_d==j)
                        res++;
                }
            }
        return res;
    }
    
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,int& row_d, int& col_d)
    {
        int row=board.size();
        int col=board[0].size();
        if(i<0||j<0||i>=row||j>=col||board[i][j]=='.'||visited[i][j]==true)
            return;
        visited[i][j]=true;
        row_d|=i;
        col_d|=j;
        dfs(board,visited,i-1,j,row_d,col_d);
        dfs(board,visited,i+1,j,row_d,col_d);
        dfs(board,visited,i,j-1,row_d,col_d);
        dfs(board,visited,i,j+1,row_d,col_d);
        //return;
    }
};