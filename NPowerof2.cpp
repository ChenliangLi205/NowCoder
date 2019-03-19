# include<iostream>
# include<vector>
# include<stack>
# include<string>
using namespace std;
void update(vector<char>& s)
{
    stack<char> ans;
    int bonus = 0;
    int result = 0;
    for(int i = s.size()-1;i>=0;i--)
    {
        char c = s[i];
        result = (c-'0') * 2 + bonus;
        bonus = result/10;
        result %= 10;
        ans.push(result+'0');
    }
    if(bonus!=0) ans.push(bonus+'0');
    s.clear();
    while(!ans.empty())
    {
        s.push_back(ans.top());
        ans.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<char> s;
    s.push_back('2');
    for(int i=2;i<=n;i++)
        update(s);
    for(char c: s)
        cout<<c;
    cout<<endl;
    return 0;
}