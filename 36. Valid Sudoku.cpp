class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> cube;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(row.find(board[i][j])==row.end())
                        row.insert(board[i][j]);
                    else
                        return  false;
                }
                if(board[j][i]!='.')
                {
                    if(col.find(board[j][i])==col.end())
                        col.insert(board[j][i]);
                    else
                        return false;
                }
                int cube_index=i/3*3+j/3;
                int cube_num=i%3*3+j%3;
                if(board[cube_index][cube_num]!='.')
                {
                    if(cube.find(board[cube_index][cube_num])==cube.end())
                       cube.insert(board[cube_index][cube_num]);
                    else
                       return false;
                }
            }
        }
        return true;
    }
};

//set的find insert函数
//分别检查i-th row, i-th column, i-th cube. board[i][j],board[j][i],board[cube_index][cube_num]
//注意 一定要注意！！！！i-th cude index: i/3*3+j/3,不是i+j/3!!!!!!!!!!!