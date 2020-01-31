#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void Process(string & s)
{
    vector<pair<char,int>> ch2cnt;
    for(char c : s)
    {
        bool finded=false;
        for(pair<char,int> &p : ch2cnt)
        {
            if(p.first == c)
            {
                ++p.second;
                finded = true;
                break;
            }
        }
        if(!finded) ch2cnt.push_back(pair<char,int>(c,1));
    }
    sort(ch2cnt.begin(), ch2cnt.end(),
        [](pair<char,int>& p1, pair<char,int>& p2) -> bool
         {return p1.second < p2.second;});
    int min = ch2cnt[0].second;
    while(!ch2cnt.empty() && ch2cnt[0].second == min)
    {
        char toRemove = ch2cnt[0].first;
        for(auto it = s.begin();it!=s.end();)
        {
            if(*it == toRemove) s.erase(it);
            else ++it;
        }
        ch2cnt.erase(ch2cnt.begin());
    }
    return;
}

int main()
{
    string s;
    while(cin >> s)
    {
        Process(s);
        cout << s << endl;
    }
}