#include<bits/stdc++.h>
using namespace std;

void ClearWithZero(vector<int>& v)
{
    for(auto iter = v.begin();iter!=v.end();++iter)
        *iter = 0;
    return;
}

int main()
{
    string s;
    cin >> s;
    vector<int> status;
    bool changed = false;
    for(int i=0;i<s.size();++i) status.push_back(0);
    do
    {
        ClearWithZero(status);
        changed = false;
        for(size_t i=0;i<s.size();++i)
        {
            if(s[i] == 'L')
            {
                if(i == 0) continue;
                else if(s[i-1] == '.') --status[i-1];
            }
            if(s[i] == 'R')
            {
                if(i == s.size()-1) continue;
                else if(s[i+1] == '.') ++status[i+1];
            }
        }
        for(size_t i=0;i<status.size();++i)
        {
            if(status[i] < 0)
            {
                s[i] = 'L';
                changed = true;
            }
            else if(status[i] > 0)
            {
                s[i] = 'R';
                changed = true;
            }
        }
    } while(changed);
    cout << s << endl;
    return 0;
}