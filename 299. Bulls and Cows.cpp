class Solution {
public:
    string getHint(string secret, string guess) {
        int len=secret.length();
        int bulls=0;
        int cows=0;
        unordered_map<int,int> secretmap;
        for(int i=0;i<len;i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                secret[i]='a';
                guess[i]='a';
            }
            else
            {
                int cur=secret[i]-'0';
                secretmap[cur]++;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(guess[i]!='a')
            {
                int cur=guess[i]-'0';
                if(secretmap.find(cur)!=secretmap.end()&&secretmap[cur]>0)
                {
                    cows++;
                    secretmap[cur]--;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};