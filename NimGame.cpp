#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    istringstream is(s);
    vector<int> offices;
    int num;
    char ch;
    while(is>>num)
    {
        offices.push_back(num);
        is >> ch;
    }
    int fuck = offices[0]^offices[1]^offices[2];
    if(fuck==0)
    {
        cout<<1<<endl;
        return 0;
    }
    s = "ABC";
    for(int i=0;i<=2;i++)
    {
        for(int j=1;j<=offices[i];j++)
        {
            offices[i] -= j;
            fuck = offices[0]^offices[1]^offices[2];
            if(fuck==0)
            {
                cout<<s[i]<<","<<j<<endl;
                return 0;
            }
            offices[i] += j;
        }
    }
    return 0;
}