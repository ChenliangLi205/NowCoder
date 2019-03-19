# include<iostream>
# include<string>
# include<vector>
# include<algorithm>
using namespace std;

vector<string> line2strvec(string line){
    string tmp;
    vector<string> res;
    for(char c: line){
        if(c==' ') {res.push_back(tmp);tmp="";continue;}
        tmp += c;
    }
    if(!tmp.empty())
        res.push_back(tmp);
    return res;
}

pair<int,int> string2interval(string s)
{
    int res = 0;
    int first=0;
    int second=0;
    for(char c: s){
        if(c==','){first = res;res = 0;continue;}
        if(res>0) res*= 10;
        res += c-'0';
    }
    second = res;
    return make_pair(first, second);
}

void merge(pair<int,int>& p1, pair<int,int>& p2)
{
    if(p1.second < p2.second) p1.second = p2.second;
}

bool smaller(pair<int,int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main(){
    string line;
    getline(cin, line);
    vector<string> s = line2strvec(line);
    vector<pair<int,int>> Intervals;
    for(string str:s)
        Intervals.push_back(string2interval(str));
    sort(Intervals.begin(), Intervals.end(), smaller);
    vector<pair<int,int>> ans;
    ans.push_back(Intervals[0]);
    for(int i=1;i<Intervals.size();i++){
        auto p = Intervals[i];
        if(ans.back().second >= p.first)
            merge(ans.back(), p);
        else
            ans.push_back(p);
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i].first<<","<<ans[i].second<<" ";
    }
    cout<<ans.back().first<<","<<ans.back().second<<endl;
    return 0;
}
