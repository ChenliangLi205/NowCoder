# include<iostream>
# include<vector>
# include<string>
# include<map>
# include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    map<char, int> char2cnt;
    for(char c: s)
    {
        if(char2cnt.find(c) == char2cnt.end())
            char2cnt.insert({c, 0});
        char2cnt[c]++;
    }
    vector<int> cnts;
    int totalCnts = 0;
    for(auto it = char2cnt.begin();it!=char2cnt.end();it++)
    {
        cnts.push_back(it->second);
        totalCnts += it->second;
    }
    if(totalCnts <= k)
    {
        cout<<0<<endl;
    }
    else if(cnts.size() == 1)
    {
        cout<<(cnts.back()-k)*(cnts.back()-k)<<endl;
    }
    else
    {
        sort(cnts.begin(), cnts.end());
        while(k>0)
        {
            int toDelete = cnts.back() - cnts[cnts.size()-2] + 1;
            if(k <= toDelete)
            {
                cnts.back() -= k;
                break;
            }
            cnts.back() -= toDelete;
            k -= toDelete;
            int toPut = cnts.back();
            cnts.pop_back();
            for(auto it=cnts.begin();it!=cnts.end();it++)
            {
                if(*it > toPut)
                {
                    cnts.insert(it, toPut);
                    break;
                }
            }
        }
        int res = 0;
        for(int i: cnts) res += i*i;
        cout<<res<<endl;
    }
    return 0;
}