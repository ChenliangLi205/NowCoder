#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int counts[26] = {0};
    for(char c : s)
    {
        counts[c-'a']++;
    }
    for(int i=0;i<26;++i)
    {
        if(counts[i] != 0)
            cout<<char('a'+i)<<counts[i];
    }
    cout<<endl;
    return 0;
}
