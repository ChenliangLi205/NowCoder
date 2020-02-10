#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;

int cal(const string& command, map<char,pair<int,int>>& matrices)
{
    int res=0;
    stack<pair<int,int>> s;
    for(char c : command)
    {
        if(c == '(') continue;
        else if(c == ')')
        {
            if(s.size() >= 2)
            {
                pair<int,int> p1, p2;
                p1 = s.top();
                s.pop();
                p2 = s.top();
                s.pop();
                res += p1.second * p2.first * p2.second;
                s.push(pair<int,int>(p2.first, p1.second));
            }
        }
        else
            s.push(matrices[c]);
    }
    return res;
}

int main()
{
    int n;
    while(cin >> n)
    {
        map<char,pair<int,int>> matrices;
        int tmp1,tmp2;
        string command;
        for(int i=0;i<n;++i)
        {
            cin >> tmp1 >> tmp2;
            matrices['A'+(char)i] = pair<int,int>(tmp1, tmp2);
        }
        cin >> command;
        cout << cal(command, matrices) << endl;
    }
    return 0;
}
