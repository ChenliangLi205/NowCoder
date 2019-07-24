#include<iostream>
#include<vector>

using namespace std;

int main()
{
    long res = 0;
    long n;
    cin>>n;
    vector<long> v(n,0);
    for(size_t i=0;i<n;++i) cin>>v[i];
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if(n == 2)
    {
        if(v[0] == v[1]) cout << v[0] << endl;
        else cout << v[1] << endl;
        return 0;
    }
    size_t p1 = 0, p2=v.size() - 1;
    long left = v[0], right = v[v.size()-1];
    while(p2 >= p1)
    {
        if(right > left) left += v[++p1];
        else if(right < left) right += v[--p2];
        else 
        {
            res = left > res ? left : res;
            left += v[++p1];
            right += v[--p2];
        }
    }
    cout << res << endl;
    return 0;
}
