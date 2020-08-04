class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> pos;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    pos.push_back(make_pair(i,j));
            }
        for (auto k:pos)
        {
            set(matrix,k.first,k.second);
        }
    }
    void set(vector<vector<int>>& matrix, int i, int j)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int p=0;p<m;p++)
            matrix[p][j]=0;
        for(int q=0;q<n;q++)
            matrix[i][q]=0;
    }
};