class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.empty()==true)
            return -1;
        int resa=helper(A,B,A[0]);
        int resb=helper(A,B,B[0]);
        if(resa!=-1)
            return resa;
        else
            return resb;


    }
    int helper(vector<int>& A, vector<int>& B,int target)
        {
            int a=0;
            int b=0;
            for(int i=0;i<A.size();i++)
            {
                if(A[i]!=target&&B[i]!=target)
                    return -1;
                if(A[i]!=target&&B[i]==target)
                    a++;
                if(A[i]==target&&B[i]!=target)
                    b++;
            }
            return min(a,b);
        }
};

//A[0],B[0]如果不相等且return不为-1，必须有且只有一个target
//这么简单的题目居然写了大半天，状态真是差到家了！！！！！！