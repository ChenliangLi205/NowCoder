#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

int main()
{
    int n;
    int dp[1000001];
    int len = 1;
    int j;
    vector<pair<int,int> > wls;
    cin>>n;
    int w,l;
    for(int i=0;i<n;++i)
    {
        cin>>w>>l;
        wls.push_back(make_pair(w,l));
    }
    
    sort(wls.begin(), wls.end(), cmp);
    vector<int> ls;
    for(auto wl : wls) ls.push_back(wl.second);
    
    dp[1] = ls[0];
    for(int i=1;i<ls.size();++i)
    {
        if(ls[i] >= dp[len])
            dp[++len] = ls[i];
        else
        {
            j = lower_bound(dp, dp+len, ls[i])-dp;
            dp[j] = ls[i];
        }
    }
    //for(int t=0;t<ls.size();++t)
        //cout<<dp[t]<<" ";
    //cout<<endl;
    cout<<len<<endl;
    return 0;
}