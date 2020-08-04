class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j]&1==1)// current:live
                {
                    if(getnei(board,i,j)==2||getnei(board,i,j)==3)//still live
                        board[i][j]=3;
                    else
                        continue;
                }
                else if(board[i][j]||0==0)// current:die
                {
                    if(getnei(board,i,j)==3)
                        board[i][j]=2;// live for next state
                }
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j]=board[i][j]>>1;
        
    }
    int getnei(vector<vector<int>>& board,int a,int b)
    {
        int m=board.size();
        int n=board[0].size();
        int res=0;
        for(int i= max(0,a-1);i<min(m,a+2);i++)
            for(int j=max(0,b-1);j<min(n,b+2);j++)
            {
                if(board[i][j]&1==1)
                    res++;
                else
                    continue;
            }
        res-=board[a][b]&1;
        return res;
    }
};

//这题要总结的有很多

//1. 边界条件的判断
//用min max函数来进行边界的控制

//2. 用00-11来表示状态转移并用右移运算符进行计算

//3. 注意判断死亡状态的条件 ||0==0 而不是&1==0

//4. 注意==和=千万别弄混了，已经连续两天犯这样的错误了