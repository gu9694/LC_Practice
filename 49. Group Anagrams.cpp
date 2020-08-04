class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mymap;
        int len=strs.size();
        if(len==0)
            return {};
        for(int i=0;i<len;i++)
        {
            string value=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(value);
        }
        vector<vector<string>> res;
        for(auto& element: mymap)
        {
            res.push_back(element.second);
        }
        return res;
    }
};

//sort函数没有返回值
//string当成vector一样用
//unordered_map mymap[index].push_back(value)