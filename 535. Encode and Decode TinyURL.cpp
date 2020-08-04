class Solution {
private:
    unordered_map<string,string> l_to_s;
    unordered_map<string,string> s_to_l;
    string dict="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str="";
        do{
            for(int i=0;i<7;i++)
            {
                int index=rand()%62;
                str.push_back(dict[index]);
            }
        }while(s_to_l.find(str)!=s_to_l.end());
        l_to_s[longUrl]=str;
        s_to_l[str]=longUrl;
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s_to_l[shortUrl];
    }

};

//对于任意一个长string，任意生成七位的密码，利用两个map完成映射
//密码与长url的长度无关
