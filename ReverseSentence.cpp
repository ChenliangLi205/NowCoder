#include<stack>
class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() == 0) return str;
        stack<string> s;
        string word;
        for(char ch : str)
        {
            if(ch==' ')
            {
                s.push(word);
                word.clear();
            }
            else
            {
                word += ch;
            }
        }
        s.push(word);
        string newStr;
        while(s.size() > 1)
        {
            newStr += s.top();
            s.pop();
            newStr += ' ';
        }
        newStr += s.top();
        return newStr;
    }
};