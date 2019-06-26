#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char> sta;
    for(char c : s)
    {
        if(sta.empty()) sta.push(c);
        else
        {
            if(c==')' && sta.top()=='(') sta.pop();
            else sta.push(c);
        }
    }
    cout<<sta.size()<<endl;
    return 0;
}
