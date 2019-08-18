#include<bits/stdc++.h>
using namespace std;

const int DP_LEN = 1000;

int main()
{
    // initialize
    string s;
    cin >> s;
    int dp[DP_LEN][DP_LEN];
    memset(dp, 0, sizeof(dp));
    size_t length, start_pos, end_pos;
    for(start_pos=0;start_pos < s.size();++start_pos) dp[start_pos][start_pos] = 1;
    // dp
    for(length=2;length<=s.size();++length)
    {
        for(start_pos=0;start_pos+length-1<s.size();++start_pos)
        {
            end_pos = start_pos + length - 1;
            dp[start_pos][end_pos] = max(dp[start_pos+1][end_pos],
                                         dp[start_pos][end_pos-1]);
            if(s[start_pos] == s[end_pos])
            {
                if(length==2)
                    dp[start_pos][end_pos] = 2;
                else
                {
                    dp[start_pos][end_pos] = max(dp[start_pos+1][end_pos-1]+2,
                                                 dp[start_pos][end_pos]);
                }
            }
        }
    }
    cout << dp[0][s.size()-1] << endl;
    return 0;
}
