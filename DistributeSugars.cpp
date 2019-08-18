#include<bits/stdc++.h>
using namespace std;
int main()
{
    //read data
    string Gstr, Sstr;
    getline(cin, Gstr);
    getline(cin, Sstr);
    istringstream Gis(Gstr), Sis(Sstr);
    int buf;
    vector<int> gs, ss;
    while(Gis >> buf)
    {
        gs.push_back(buf);
    }
    while(Sis >> buf)
    {
        ss.push_back(buf);
    }
    // do algorithm
    sort(gs.begin(), gs.end());
    sort(ss.begin(), ss.end());
    int kids=0,s_pos=0,g_pos=0;
    while(s_pos < ss.size() && g_pos < gs.size())
    {
        if(ss[s_pos++] >= gs[g_pos])
        {
            ++g_pos;
            ++kids;
        }
    }
    cout << kids << endl;
    return 0;
}