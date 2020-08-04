class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> q1;
        queue<int> q2;
        int len1=version1.length();
        int len2=version2.length();
        int num1=0;
        int num2=0;
        for(int i=0;i<len1;i++)
        {
            if(isdigit(version1[i]))
            {
                num1=10*num1+version1[i]-'0';
            }
            if(version1[i]=='.'||i==len1-1)
            {
                q1.push(num1);
                num1=0;
            }
        }
        for(int i=0;i<len2;i++)
        {
            if(isdigit(version2[i]))
            {
                num2=10*num2+version2[i]-'0';
            }
            if(version2[i]=='.'||i==len2-1)
            {
                q2.push(num2);
                num2=0;
            }
        }
        while(q1.empty()==false&&q2.empty()==false)
        {
            int v1=q1.front();
            int v2=q2.front();
            q1.pop();q2.pop();
            if(v1>v2)
                return 1;
            if(v1<v2)
                return -1;
        }
        if(q1.empty()==false)
        {
            while(q1.empty()==false)
            {
                int check1=q1.front();
                q1.pop();
                if(check1!=0)
                    return 1;
            }
            return 0;
        }
        if(q2.empty()==false)
        {
            while(q2.empty()==false)
            {
                int check2=q2.front();
                q2.pop();
                if(check2!=0)
                    return -1;
            }
            return 0;
        }
        return 0;
    }
};