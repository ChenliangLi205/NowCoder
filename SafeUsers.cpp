#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Graph
{
private:
    set<int> nodes;
    map<int, set<int>> body;
public:
    Graph();
    void AddNode(int);
    void AddEdge(int,int);
    void AddEdge(pair<int,int>);
    void DeleteNode(int);
    vector<int> ZeroNodes();
};

Graph::Graph(){}

void Graph::AddNode(int n)
{
    nodes.insert(n);
    if(body.find(n)==body.end()) body[n]=set<int>();
    return;
}

void Graph::AddEdge(int a, int b)
{
    AddNode(a);
    AddNode(b);
    body[a].insert(b);
    return;
}

void Graph::AddEdge(pair<int,int> e)
{
    AddEdge(e.first, e.second);
    return;
}

void Graph::DeleteNode(int n)
{
    nodes.erase(n);
    body.erase(n);
    for(auto it=body.begin();it!=body.end();it++)
    {
        it->second.erase(n);
    }
    return;
}

vector<int> Graph::ZeroNodes()
{
    vector<int> res;
    for(auto it=nodes.begin();it!=nodes.end();it++)
    {
        if(body[*it].empty()) res.push_back(*it);
    }
    return res;
}

pair<int,int> str2edge(string s)
{
    pair<int,int> res(0,0);
    int tmp=0;
    for(char c : s)
    {
        if(c==',')
        {
            res.first = tmp;
            tmp = 0;
        }
        else
        {
            tmp *= 10;
            tmp += c-'0';
        }
    }
    res.second = tmp;
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Graph g;
    string s;
    pair<int,int> edge;
    for(int i=1;i<=n;i++) g.AddNode(i);
    for(int i=0;i<m;i++)
    {
        cin>>s;
        edge = str2edge(s);
        g.AddEdge(edge);
    }
    vector<int> SafeUsers;
    vector<int> ZNodes = g.ZeroNodes();
    while(!ZNodes.empty())
    {
        for(int node: ZNodes)
        {
            SafeUsers.push_back(node);
            g.DeleteNode(node);
        }
        ZNodes = g.ZeroNodes();
    }
    if(SafeUsers.empty()) cout<<"None"<<endl;
    else
    {
        sort(SafeUsers.begin(), SafeUsers.end());
        for(vector<int>::size_type i=0;i<SafeUsers.size()-1;i++)
            cout<<SafeUsers[i]<<" ";
        cout<<SafeUsers.back()<<endl;
    }
    return 0;
}
