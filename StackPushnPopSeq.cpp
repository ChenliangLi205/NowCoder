#include<stack>
#include<set>
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() && popV.empty()) return true;
        int n;
        stack<int> s;
        vector<int>::size_type popIdx=0;
        for(vector<int>::size_type i=0;i<pushV.size();i++)
        {
            if(pushV[i]!=popV[popIdx])
            {
                s.push(pushV[i]);
            }
            else
            {
                popIdx++;
                while(!s.empty() && s.top()==popV[popIdx] && popIdx<popV.size())
                {
                    s.pop();
                    popIdx++;
                }
            }
        }
        return s.empty();
    }
};