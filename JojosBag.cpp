# include<iostream>
using namespace std;
int main()
{
    int n,v;
    cin>>n>>v;
    int* Ms = new int[n];
    int* Ws = new int[n];
    int* Ss = new int[n];
    for(int i=0;i<n;i++)
        cin>>Ms[i]>>Ws[i]>>Ss[i];
    int* dp = new int[v+1];
    for(int i=0;i<=v;i++) dp[i] = 0;
    for(int i=0;i<n;i++)
        for(int j=v;j>=Ws[i];j--)
            for(int k=1;k<=Ms[i] && k*Ws[i] <= j;k++)
                dp[j] = dp[j] > dp[j-k*Ws[i]]+k*Ss[i] ? dp[j] : dp[j-k*Ws[i]]+k*Ss[i];
    cout << dp[v];
    return 0;
}