class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row=A.size();
        int col=B[0].size();
        vector<int> tmp(col,0);
        vector<vector<int>> res;
        for(int i=0;i<row;i++)
            res.push_back(tmp);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cal(A,B,i,j,res);
        return res;
    }
    
    void cal(vector<vector<int>>& A, vector<vector<int>>& B, int row, int col, 
            vector<vector<int>>& res)
    {
        int len=A[0].size();
        int sum=0;
        for(int k=0;k<len;k++)
            sum+=A[row][k]*B[k][col];
        res[row][col]=sum;
        return;
    }
};