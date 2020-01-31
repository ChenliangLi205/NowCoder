#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void deleteRepeat(vector<int>& v)
{
    for(auto it=v.begin()+1;it!=v.end();)
    {
        if(*it == *(it-1)) v.erase(it);
        else ++it;
    }
    return;
}

vector<bool> checkVisited(const vector<int>& v)
{
    vector<bool> res;
    set<int> s;
    for(int i: v)
    {
        if(s.find(i) != s.end()) res.push_back(true);
        else
        {
            s.insert(i);
            res.push_back(false);
        }
    }
    return res;
}

string itos(int i)
{
    string s;
    while(i > 0)
    {
        s += (char)(i%10) + '0';
        i /= 10;
    }
    return s;
}

bool inside(int i1, int i2)
{
    string s1 = itos(i1),
           s2 = itos(i2);
    return s2.find(s1) != string::npos;
}

map< int, vector< pair<int,int> > > checkContain(const vector<int>& I,
                                    const vector<int>& R)
{
    map< int, vector< pair<int,int> > > res;
    vector<bool> visited = checkVisited(I);
    for(int r: R)
    {
        for(int i=0 ; i < I.size() ; ++i)
        {
            if(visited[i])
                continue;
            if(inside(r, I[i]))
            {
                if(res.find(r) == res.end())
                    res[r] = vector< pair<int,int> >();
                res[r].push_back(pair<int,int>(i, I[i]));
            }
        }
    }
    return res;
}

int countInt(const map< int, vector< pair<int,int> > >& m)
{
    int res=0;
    for(auto it=m.begin();it!=m.end();++it)
    {
        res += 2;
        res += (it->second).size()*2;
    }
    return res;
}

void show(const map< int, vector< pair<int,int> > >& m)
{
    for(auto it=m.begin();it!=m.end();++it)
    {
        cout << it->first << " ";
        cout << (it->second).size() << " ";
        for(pair<int,int> p : it->second)
        {
            cout << p.first << " ";
            cout << p.second << " ";
        }
    }
    cout << endl;
    return;
}

int main()
{
    int n_i, n_r, tmp;
    while(cin >> n_i)
    {
        vector<int> R,I;
        for(int i=0;i<n_i;++i)
        {
            cin >> tmp;
            I.push_back(tmp);
        }
        cin >> n_r;
        for(int i=0;i<n_r;++i)
        {
            cin >>tmp;
            R.push_back(tmp);
        }
        sort(R.begin(), R.end());
        deleteRepeat(R);
        auto m = checkContain(I, R);
        cout << countInt(m)<<" ";
        show(m);
    }
    return 0;
}