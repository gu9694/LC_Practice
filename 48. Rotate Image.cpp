class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size();
        int mid=len/2;
        int top=0;
        int down=len-1;
        while(top<down)
        {
            swap(matrix[top],matrix[down]);
            top++;
            down--;
        }
        
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
    }
};

//没啥技巧 就是硬背 先上下互换，然后对角线互换