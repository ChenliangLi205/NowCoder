#include <iostream>
#include <vector>

using namespace std;

vector <pair<int,int>> curPath, minPath;
int r,c;

void solve(int x, int y, vector< vector<int> >& maze)
{
    curPath.push_back(pair<int,int>(x,y));
    maze[x][y] = 1;
    
    if(!minPath.empty() && curPath.size() >= minPath.size())
    {
        maze[x][y] = 0;
        curPath.pop_back();
        return;
    }
    
    if(x == r-1 && y == c-1)
    {
        if(minPath.empty() || curPath.size() < minPath.size())
            minPath = curPath;
    }
    else
    {
        if(x <= r-2 && maze[x+1][y] == 0)
            solve(x+1, y, maze);
        if(y <= c-2 && maze[x][y+1] == 0)
            solve(x, y+1, maze);
        if(x >0 && maze[x-1][y] == 0)
            solve(x-1, y, maze);
        if(y > 0 && maze[x][y-1] == 0)
            solve(x, y-1, maze);
    }
    
    maze[x][y] = 0;
    curPath.pop_back();
    return;
}

int main()
{
    while(cin >> r >> c)
    {
        curPath.clear();
        minPath.clear();
        vector< vector<int> > maze(r, vector<int>(c, 0));
        for(auto &i : maze)
            for(auto &j : i)
                cin >> j;
        solve(0, 0 , maze);
        for(auto p : minPath)
            cout << "(" << p.first << "," << p.second << ")" << endl;
    }
    return 0;
}
