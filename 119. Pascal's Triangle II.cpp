class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        vector<int> pre;
        if(rowIndex==0)
            return {1};
        if(rowIndex==1)
            return {1,1};
        if(rowIndex==2)
            return {1,2,1};
        else
        {
            vector<int> tmp(2,1);
            for(int i=3;i<=rowIndex+1;i++)
            {
                vector<int> cur(i);
                cur[0]=1;
                cur[i-1]=1;
                for(int j=1;j<i-1;j++)
                    cur[j]=tmp[j-1]+tmp[j];
                tmp=cur;
                if(i==rowIndex+1)
                    res=cur;
            }
        }
        return res;
    }
};