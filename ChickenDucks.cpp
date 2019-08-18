#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s.empty())
    {
        cout << 0 <<endl;
    }
    else
    {
        int d_moves = 0, c_moves = 0;
        int pos = s.size()-1;
        int c_cnts = 0, d_cnts = 0;
        for(pos = s.size()-1;pos >= 0;--pos)
        {
            if(s[pos] == 'D')
            {
                d_moves += c_cnts;
                ++d_cnts;
            }
            else
            {
                c_moves += d_cnts;
                ++c_cnts;
            }
        }
        cout << min(d_moves, c_moves) << endl;
    }
    return 0;
}