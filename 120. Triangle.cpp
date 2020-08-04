class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int level=triangle.size();
        for(int i=1;i<level;i++)
        {
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][i]+=triangle[i-1][i-1];
            for (int j=1;j<level;j++)
                triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
        }
        return *min_element(triangle[level-1].begin(),triangle[level-1].end());
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.empty()==true )
        return 0;
    int m = triangle.size();
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0)
                triangle[i][j] = triangle[i-1][j] + triangle[i][j];
            else if(j==triangle[i].size()-1)
                triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
            else
                triangle[i][j] = min(triangle[i-1][j-1],triangle[i-1][j]) + triangle[i][j];
        }
    }
    return *min_element(triangle[triangle.size()-1].begin(),
                        triangle[triangle.size()-1].end());
}
};
//从下往上更新更简单
