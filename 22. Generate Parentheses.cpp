
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }
 
    void generate(int left, int right, string str, vector<string>& res)
    {
        if(left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }
        if(left > 0)
        {
            generate(left - 1, right, str + '(', res);
        }
        if(right > left)
        {
            generate(left, right - 1, str + ')', res);
        }
    }
};

//递归算法其实我一直搞不太清楚
//写函数一定要考虑是不是要加上&
//如果不加的话只是在函数内部改变形参的值
//如果该函数没有返回值，那么在外部不改变参数的值