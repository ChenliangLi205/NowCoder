#include<iostream>
#include<vector>
using namespace std;

int min3(int a, int b, int c)
{
    int mid;
    mid = a < b ? a : b;
    mid = mid < c ? mid : c;
    return mid;
}

int min2(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int x;
    cin>>x;
    if(x==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(x < 0) x = -x;
    vector<int> dp(x+2,x);
    dp[0] = 0;
    for(int i=1;i<x+1;i++)
    {
        if(i%2==0)
        {
            dp[i] = min3(dp[i],dp[i-1]+1,dp[i/2]+1);
        }
        else
        {
            dp[i] = min3(dp[i+1]+1, dp[i-1]+1, dp[i]);
        }
        if(i*2 < x+2) dp[i*2] = min2(dp[i]+1,dp[i*2]); 
    }
    cout<<dp[x]<<endl;
    return 0;
}