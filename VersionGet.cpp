# include<stdio.h>
# include<iostream>
# include<string>
# include<map>
# include<vector>
# include<sstream>
# include<algorithm>
using namespace std;

int string2num(string& str)
{
    istringstream iss(str);
    int num;
    iss>>num;
    return num;
}

int main()
{
    int n;
    cin>>n;
    map<int, map<int, vector<int>>> versionMap;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d.%d.%d", &a, &b, &c);
        if(versionMap.find(a) == versionMap.end())
            versionMap.insert({a, map<int, vector<int>>()});
        if(versionMap[a].find(b) == versionMap[a].end())
            versionMap[a].insert({b, vector<int>()});
        versionMap[a][b].push_back(c);
    }
    int qa=-1, qb=-1, qc=-1;
    scanf("%d.%d.%d", &qa, &qb, &qc);
    vector<int> currentLayer;
    if(qb == -1)
    {
        if(versionMap.find(qa) == versionMap.end())
        {
            cout<<0<<endl;
        }
        else
        {
            vector<int> secondLayer;
            for(auto it = versionMap[qa].begin();it != versionMap[qa].end();it++)
                secondLayer.push_back(it->first);
            int max_index_second = *max_element(secondLayer.begin(), secondLayer.end());
            vector<int> thirdLayer = versionMap[qa][max_index_second];
            int max_index_third = *max_element(thirdLayer.begin(), thirdLayer.end());
            printf("%d.%d.%d", qa, max_index_second, max_index_third);
        }
    }
    else if(qc==-1)
    {
        if(versionMap.find(qa) == versionMap.end() || versionMap[qa].find(qb) == versionMap[qa].end())
        {
            cout<<0<<endl;
        }
        else
        {
            vector<int> thirdLayer = versionMap[qa][qb];
            int max_idx = *max_element(thirdLayer.begin(), thirdLayer.end());
            printf("%d.%d.%d", qa, qb, max_idx);
        }
    }
    else
    {
        if(versionMap.find(qa) == versionMap.end() || versionMap[qa].find(qb) == versionMap[qa].end())
        {
            cout<<0<<endl;
        }
        else
        {
            vector<int> thirdLayer = versionMap[qa][qb];
            int idx = -1;
            for(int n_: thirdLayer)
                if(n_ == qc)
                {
                    printf("%d.%d.%d", qa, qb, qc);
                    idx = qc;
                    break;
                }
            if(idx == -1) cout<<0<<endl;
        }
    }
    return 0;
}