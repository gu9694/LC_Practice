class Solution {
public:
    int numJewelsInStones(string J, string S) {
        //int len_j=J.length();
        int len_s=S.length();
        unordered_set<char> mymap;
        
        mymap.insert(J.begin(),J.end());
        
        int num=0;
        for(int i=0;i<len_s;i++)
        //for(char stone:S)
            if(mymap.find(S[i])!=mymap.end())
            {
                num++;
            }
        return num;
    }
};

//unordered_set find函数的返回值是元素的迭代器 否则返回end
//不是false true 写判断条件的时候要注意