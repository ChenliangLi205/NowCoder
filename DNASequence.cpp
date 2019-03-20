# include<string>
# include<set>
# include<vector>
# include<iostream>
using namespace std;

int Length(string s){
    if(s.size() == 0) return 0;
    if(s.size() < 4) return 1;
    set<string> seqSet;
    int p1=0;
    int len = 1;
    int expected = 4;
    while(len<=s.size())
    {
        while(p1+len<=s.size()){
            seqSet.insert(s.substr(p1,len));
            ++p1;
        }
        if(seqSet.size() < expected) return len;
        expected *= 4;
        p1 = 0;
        ++len;
        seqSet.clear();
    }
    return (int)s.size();
}

int main(){
    string s;
    cin>>s;
    cout<<Length(s)<<endl;
    return 0;
}