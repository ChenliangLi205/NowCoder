# include<iostream>
using namespace std;

int max(int i1, int i2)
{
    return i1 > i2 ? i1 : i2;
}

int main()
{
    int m;
    cin>>m;
    int* metrix = new int[m];
    int zero_cnt = 0;
    for(int i=0;i<m;i++)
    {
        cin>>metrix[i];
        if(metrix[i] == 0) zero_cnt++;
    }
    int n;
    cin>>n;
    if(zero_cnt < n) cout<<"false"<<endl;
    else
    {
        int* dp = new int[m];
        if(metrix[0]==1) dp[0] = 0;
        else dp[0] = 1;
        for(int i=1;i<m;i++)
        {
            if(metrix[i] == 1)
            {
                if(i==1) dp[i] = 0;
                else dp[i] = dp[i-2];
            }
            else
            {
                if(i==1)
                {
                    if(metrix[i] == 0 && metrix[i-1] == 0) dp[i] = 1;
                    else dp[i] = 0;
                }
                else
                {
                    dp[i] = max(dp[i-2]+1, dp[i-1]);
                }
            }
        }
        if(dp[m-1] >= n) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}