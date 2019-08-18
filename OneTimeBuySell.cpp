#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int value;
    while(cin>>value)
        v.push_back(value);
    vector<int> min_sofar;
    int min_val_sofar = 0x7fffffff;
    for(int val : v)
    {
        min_val_sofar = val < min_val_sofar ? val : min_val_sofar;
        min_sofar.push_back(min_val_sofar);
    }
    int max_profit=-0x7fffffff;
    for(int i=v.size()-1;i>=0;--i)
    {
        max_profit = max_profit > v[i]-min_sofar[i] ? max_profit : v[i]-min_sofar[i];
    }
    cout << max_profit << endl;
    return 0;
}