#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int k,n;
    cin>>k>>n;
    queue<vector<int>> Combs;
    queue<int> Results;
    vector<int> comb;
    int r;
    vector<vector<int>> ans;
    for(int i=1;i<=9;i++)
    {
        Combs.push(vector<int>(1,i));
        Results.push(i);
    }
    while(!Combs.empty())
    {
        comb = Combs.front();
        Combs.pop();
        r = Results.front();
        Results.pop();
        if(r > n) continue;
        if(comb.size()==k)
        {
            if(r==n) ans.push_back(comb);
        }
        for(int i=comb.back()+1;i<=9;i++)
        {
            vector<int> newComb = comb;
            newComb.push_back(i);
            Combs.push(newComb);
            Results.push(r+i);
        }
    }
    if(!ans.empty())
    {
        for(auto v:ans)
        {
            for(int i=0;i<v.size()-1;i++)
                cout<<v[i]<<" ";
            cout<<v.back()<<endl;
        }
    }
    else
    {
        cout<<"None"<<endl;
    }
    return 0;
}