#include<iostream>

using namespace std;

int main()
{
    long long a,b,m;
    cin>>a>>b>>m;
    long long res=1LL;
    long long bot = a;
    while(b>0)
    {
        if(b&1) res = (res*bot) % m;
        b >>= 1;
        bot = (bot*bot) % m;
    }
    cout << res%m << endl;
    return 0;
}
