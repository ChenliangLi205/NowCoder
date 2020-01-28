#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkSub(const string& password)
{
    size_t length = 3;
    size_t left=0,right=3;
    while(length <= password.size() / 2)
    {
        size_t left=0, right=length;
        while(right <= password.size())
        {
            string sub = password.substr(left, length);
            string remains = password.substr(right, password.size()-length);
            if(remains.find(sub) != string::npos) return false;
            ++left;
            ++right;
        }
        ++length;
    }
    return true;
}

bool isValid(const string& password)
{
    if(password.size() <= 8) return false;
    bool upper=false, lower=false,
    number=false, symbol=false;
    int types=0;
    for(char c : password)
    {
        if(c >= 'A' && c <= 'Z') upper=true;
        else if(c >= 'a' && c <= 'z') lower = true;
        else if(c >= '0' && c<= '9') number = true;
        else symbol = true;
    }
    if(upper) ++types;
    if(lower) ++types;
    if(number) ++types;
    if(symbol) ++types;
    if(types < 3) return false;
    return checkSub(password);
}

int main()
{
    vector<string> password;
    string tmp;
    while(getline(cin,tmp))
    {
        password.push_back(tmp);
    }
    for(string s : password)
    {
        if(isValid(s))
            cout << "OK" << endl;
        else cout << "NG" << endl;
    }
    return 0;
}