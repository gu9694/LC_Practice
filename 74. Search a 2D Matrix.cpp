class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0)
            return false;
        int low=0;
        int high=m*n-1;
        if(target<matrix[0][0]||target>matrix[m-1][n-1])
            return false;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]>target)
                high=mid-1;
            if(matrix[row][col]<target)
                low=mid+1;
        }
        return false;
    }
};

//虽然是一个二维数组 但是还是和一维数组二分搜索一样
//while(row<=high)
//matrix[mid/n][mid%n]