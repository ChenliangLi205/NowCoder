#include<bits/stdc++.h>
using namespace std;

const int MAX_LEN=10000;

int main()
{
    string s;
    cin >> s;
    int dp[MAX_LEN] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(size_t i=2;i<=s.size();++i)
    {
        dp[i] = dp[i-1];
        if((s[i-1] <= '6' && s[i-2] == '2') || (s[i-1] <= '9' && s[i-2] == '1'))
            dp[i] += dp[i-2];
    }
    cout << dp[s.size()] << endl;
    return 0;
}