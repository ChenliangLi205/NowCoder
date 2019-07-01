#include<algorithm>
#include<set>
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty()) return res;
        if(str.size()==1)
        {
            res.push_back(str);
            return res;
        }
        sort(str.begin(), str.end());
        set<char> visited;
        for(string::size_type i=0;i<str.size();i++)
        {
            if(visited.find(str[i])!=visited.end()) continue;
            vector<string> subRes = PermutationHelper(str.substr(0,i)
                                                +str.substr(i+1,str.size()-1-i));
            for(string s : subRes)
            {
                res.push_back(str[i]+s);
            }
            visited.insert(str[i]);
        }
        return res;
    }
    
    vector<string> PermutationHelper(string str)
    {
        vector<string> res;
        if(str.empty()) return res;
        if(str.size()==1)
        {
            res.push_back(str);
            return res;
        }
        set<char> visited;
        for(string::size_type i=0;i<str.size();i++)
        {
            if(visited.find(str[i])!=visited.end()) continue;
            vector<string> subRes = PermutationHelper(str.substr(0,i)
                                                +str.substr(i+1,str.size()-1-i));
            for(string s : subRes)
            {
                res.push_back(str[i]+s);
            }
            visited.insert(str[i]);
        }
        return res;
    }
};