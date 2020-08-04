class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0)
            return 0;
        if(ratings.size()==1)
            return 1;
        vector<int> res(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
            if(ratings[i]>ratings[i-1])
                res[i]=res[i-1]+1;
        for(int j=ratings.size()-2;j>=0;j--)
            if(ratings[j]>ratings[j+1])
                res[j]=max(res[j],res[j+1]+1);
        int sum=0;
        for(auto k:res)
            sum+=k;
        return sum;
    }
};

//两边遍历 第一遍保证向右符合条件 第二遍保证向左符合条件