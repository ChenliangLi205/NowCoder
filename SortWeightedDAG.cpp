# include<iostream>
# include<vector>
# include<algorithm>
# include<set>
# include<map>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second > p2.second;
}

class Graph
{
private:
    map<int, int> nodes;
    map<int, set<int>> edges;
public:
    void AddNode(int n, int w)
    {
        nodes.insert({n, w});
    }
    void AddEdge(int s, int t)
    {
        if(edges.find(s) == edges.end())
            edges.insert({s, set<int>()});
        edges[s].insert(t);
    }
    void DeleteEdge(int s, int t)
    {
        if(edges.find(s) == edges.end()||edges[s].find(t) == edges[s].end()) return;
        edges[s].erase(t);
        if(edges[s].empty())
            edges.erase(s);
    }
    void DeleteNode(int node)
    {
        nodes.erase(node);
        edges.erase(node);
    }
    vector<int> out()
    {
        map<int,int> candidates = nodes;
        vector<int> res;
        while(!nodes.empty())
        {
            vector<pair<int, int>> thisRound;
            for(auto it = edges.begin();it!=edges.end();it++)
            {
                set<int> targets = it->second;
                for(auto itt = targets.begin();itt!=targets.end();itt++)
                    candidates.erase(*itt);
            }
            for(auto it = candidates.begin();it!=candidates.end();it++)
            {
                thisRound.push_back(*it);
                DeleteNode(it->first);
            }
            sort(thisRound.begin(), thisRound.end(), comp);
            for(auto p: thisRound) res.push_back(p.first);
            candidates = nodes;
        }
        return res;
    }
};

int main()
{
    int n,e;
    cin>>n>>e;
    Graph g;
    for(int i=0;i<n;i++)
    {
        int node, weight;
        cin>>node>>weight;
        g.AddNode(node, weight);
    }
    for(int i=0;i<e;i++)
    {
        int start, target;
        cin>>start>>target;
        g.AddEdge(start, target);
    }
    vector<int> res = g.out();
    for(int i=0;i<res.size();i++)
    {
        if(i==res.size()-1) cout<<res[i];
        else cout<<res[i]<<" ";
    }
    return 0;
}