#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int buf, limit, left, right, res=0;
    while(cin >> buf)
    {
        v.push_back(buf);
    }
    limit = v.back();
    v.pop_back();
    if(v.empty())
        cout << 0 << endl;
    else if(v.size() == 1)
        cout << 1 << endl;
    else
    {
        sort(v.begin(), v.end());
        left = 0;
        right = v.size()-1;
        while(left <= right)
        {
            if(left == right)
            {
                ++res;
                break;
            }
            if(v[left] + v[right--] <= limit)
                ++left;
            ++res;
        }
        cout << res << endl;
    }
    return 0;
}