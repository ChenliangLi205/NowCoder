class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        bool neg = false;
        int start=0;
        if(str[0]=='-') {neg=true;start=1;}
        if(str[0]=='+') {neg=false;start=1;}
        int res = 0;
        for(;start<str.size();start++)
        {
            if(str[start] > '9' || str[start] < '0') return 0;
            res *= 10;
            res += str[start]-'0';
        }
        if(neg) return -res;
        else return res;
    }
};