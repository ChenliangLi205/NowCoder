#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int m,x;
        vector<int> famaType, famaNum;
        set<int> feasible;
        feasible.insert(0);
        for(int i=0;i<n;++i)
        {
            cin >> m;
            famaType.push_back(m);
        }
        for(int i=0;i<n;++i)
        {
            cin >> x;
            vector<int> alreadyHas;
            for(auto it=feasible.begin();
                it!=feasible.end();++it)
                alreadyHas.push_back(*it);
            for(int j=1;j<=x;++j)
            {
                for(int v : alreadyHas)
                    feasible.insert(v+j*famaType[i]);
            }
        }
        cout << feasible.size() << endl;
    }
    return 0;
}