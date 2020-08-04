class Solution {
public:
    struct myless{
        bool operator()(string a, string b)
        {
            string x=a+b;
            string y=b+a;
            if(x>y)
                return true;
            return false;
        }
    };

    string largestNumber(vector<int>& nums) {
        vector<string> snum;
        int mark=0;
        for(auto i: nums)
        {
            if(i!=0)
                mark=1;
            snum.push_back(to_string(i));
        }
        if(mark==0)
            return to_string(0);
        sort(snum.begin(),snum.end(),myless());
        string res;
        for(auto i: snum)
            res+=i;
        return res;
    }
};

//字符串比较大小