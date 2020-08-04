class Solution {
private:
    unordered_map <char,int> mymap{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
        
    };
    
public:
    int flag=1;
    int romanToInt(string s) {
        int res=0;
        int len=s.length();
        if (s.empty())
            return 0;
        if (len==1)
            return mymap[s[0]];
        for (int i=len-2;i>=0;i--)
        {
           if(mymap[s[i]]<mymap[s[i+1]])
             res-=mymap[s[i]];
           else
             res+=mymap[s[i]];
           

        }
        return res+mymap[s[len-1]];
    }
};