class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[m][n];
        for(int i=0;i<m;i++)
            a[i][0]=1;
        for(int j=0;j<n;j++)
            a[0][j]=1;
        for(int p=1;p<m;p++)
            for(int q=1;q<n;q++)
            {
                a[p][q]=a[p-1][q]+a[p][q-1];
            }
        return a[m-1][n-1];
    }
};