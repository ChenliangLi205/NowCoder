#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string inputStr;
    while(getline(cin, inputStr))
    {
        if(inputStr.empty())
        {
            cout << 0 << endl;
            continue;
        }
        queue<pair<int,int>> q;
        int res = 0;
        for(int i=0;i<(int)inputStr.size();++i)
        {
            q.push(pair<int,int>(i,i));
            if(i!=(int)inputStr.size()-1 && inputStr[i] == inputStr[i+1])
            {
                q.push(pair<int,int>(i,i+1));
            }
        }
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            res = res > p.second-p.first+1 ? res : p.second-p.first+1;
            if(p.first > 0 && p.second < (int)inputStr.size()-1 &&
               inputStr[p.first-1] == inputStr[p.second+1])
                q.push(pair<int,int>(p.first-1, p.second+1));
        }
        cout << res << endl;
    }
    return 0;
}
