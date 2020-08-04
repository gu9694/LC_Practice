class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()==true)
            return 0;
        if(beginWord==endWord)
            return 0;
        unordered_set<string> wl(wordList.begin(),wordList.end());//查找新单词是否在wordlist中
        unordered_map<string,int> mymap{{beginWord,1}};//初始化
        queue<string> myq;
        myq.push(beginWord);//bfs首个元素入列
        while(myq.empty()==false)//bfs
        {
            string nw;
            nw=myq.front();
            myq.pop();
            for(int i=0;i<nw.length();i++)
            {
                string tmp=nw;
                for(char c='a';c<='z';c++)
                {
                    tmp[i]=c;
                    if(wl.count(tmp)!=0&&tmp==endWord)//bfs搜索到结果
                        return mymap[nw]+1;
                    else if(wl.count(tmp)!=0&&mymap.find(tmp)==mymap.end())//保证tmp未被使用过！
                    {
                        mymap[tmp]=mymap[nw]+1;
                        myq.push(tmp);
                    }
                }
            }
        }
        return 0;
    }
};