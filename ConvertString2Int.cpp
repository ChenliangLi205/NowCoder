#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int str2int(string&& s)
{
    int res=0;
    for(char c:s)
    {
        res *= 10;
        res += c-'0';
    }
    return res;
}

int main()
{
    vector<int> numbers;
    int m;
    cin>>m;
    string str;
    int number, pos;
    while(cin>>str)
    {
        numbers.push_back(str2int(str.substr(str.size()-6,6)));
    }
    sort(numbers.begin(), numbers.end());
    for(int i : numbers) cout << i <<endl;
    return 0;
}
