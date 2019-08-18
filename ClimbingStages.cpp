#include<iostream>

#define DP_LENGTH 1001
#define MOD 1000000003

using namespace std;

int main()
{
    int M, n;
    cin >> M;
    long dp[DP_LENGTH];
    int step = 1;
    for(int _i=0;_i<M;++_i)
    {
        cin >> n;
        dp[1] = 1;
        dp[0] = 1;
        for(int i=2;i<=n;++i)
        {
            dp[i] = 0;
            step = 1;
            while(step <= i)
            {
                dp[i] += (dp[i-step]) % MOD;
                step *= 2;
            }
        }
        cout << dp[n] % MOD <<endl;
    }
    return 0;
}