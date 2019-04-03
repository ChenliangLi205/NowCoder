# include<iostream>
using namespace std;

int max(int i1, int i2)
{
    return i1 > i2 ? i1 : i2;
}

int main()
{
    int n;
    cin>>n;
    int* v = new int[n];
    for(int i=0;i<n;i++) cin>>v[i];
    int** subV = new int*[n];
    for(int i=0;i<n;i++) subV[i] = new int[n];
    for(int i=0;i<n;i++)
    {
        subV[i][i] = v[i];
        for(int j=1;j<n;j++)
        {
            if(i+j >= n) break;
            subV[i][i+j] = subV[i][i+j-1] + v[i+j];
        }
    }
    int** dp = new int*[n];
    for(int i=0;i<n;i++) dp[i] = new int[n];
    for(int i=0;i<n;i++) dp[i][i] = v[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            int k = i+j;
            if(k>=n) break;
            dp[i][k] = max(v[i]+dp[i+1][k]+subV[i+1][k],
                           v[k]+dp[i][k-1]+subV[i][k-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}