class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() <= 1) return str;
        string newStr;
        n %= str.size();
        for(int i=0;i<n;i++) newStr += str[i];
        newStr = string(str.begin()+n, str.end()) + newStr;
        return newStr;
    }
};