#include<iostream>
#include<string>
using namespace std;

int Helper(string s)
{
    if(s.size() == 0) return 1;
    if(s.size() == 1)
    {
        char c1 = s[0];
        if('0' < c1 && c1 <= '9') return 1;
        else return 0;
    }
    char c1 = s[0];
    char c2 = s[1];
    if(c1<='0' || c1>'9') return 0;
    int t1 = Helper(s.substr(1));
    if(c2<'0' || c2>'9') return 0;
    int Double = (c1-'0')*10 + (c2-'0');
    if(Double <= 26) return t1+Helper(s.substr(2));
    else return t1;
}

int main()
{
    string s;
    cin>>s;
    cout<<Helper(s)<<endl;
    return 0;
}