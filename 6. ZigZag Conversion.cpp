class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> zigzag (numRows,"");
        int step=1;
        int row=0;
        int len=s.length();
        if(len<=numRows||s.empty()==true||numRows==1)
            return s;
        for (int i=0;i<len;i++)
        {
            if(row==0)
                step=1;
            if(row==numRows-1)
                step=-1;
            zigzag[row].push_back(s[i]);
            row+=step;
        }
        string res="";
        for(string j:zigzag)
            res+=j;
        return res;
    }
};

//vector的初始化方法
//遍历zigzag的方法
