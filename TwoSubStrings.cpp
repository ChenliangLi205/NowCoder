# include<iostream>
# include<string>
# include<vector>
using namespace std;

bool comp(string s1, int start, string s2){
    for(int i=0;i<s2.size();i++)
        if(s1[start+i]!=s2[i]) return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    string ans=s;
    string::size_type it = ans.size();
    for(int i=s.size()-1;i>=0;i--)
    {
        ans.insert(it, 1, s[i]);
        if(comp(ans, s.size()-i, s)) break;
    }
    cout<<ans<<endl;
    return 0;
}
