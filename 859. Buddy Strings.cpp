class Solution {
public:
    bool buddyStrings(string A, string B) {
        int la=A.length();
        int lb=B.length();
        int diff=0;            
        if(la!=lb||la<=1||lb<=1)
            return false;
        else
        {
            vector<int> lettera;
            vector<int> letterb;
            unordered_map<char,int> mapa;
            unordered_map<char,int> mapb;
            for(int i=0;i<la;i++)
                mapa[A[i]]=0;
            for(int j=0;j<lb;j++)
                mapb[B[j]]=0;
            for(int i=0;i<la;i++)
            {
                if (A[i]==B[i])
                {
                    mapa[A[i]]++;
                    mapb[B[i]]++;
                }
                else
                {
                    diff++;
                    lettera.push_back(A[i]);
                    letterb.push_back(B[i]);
                }
            }
        if(diff==0)
        {
            for (int i=0;i<la;i++)
                if(mapa[A[i]]>=2)
                    return true;
            return false;
        }
        else if(diff==2)
        {
            if(lettera[0]==letterb[1]&&lettera[1]==letterb[0])
                return true;
            else
                return false;
        }
        else
            return false;
        }

    }
};