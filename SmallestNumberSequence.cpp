#include<algorithm>
#include<stack>
int highest(int n)
{
    while(n>=10) n/=10;
    return n;
}

string num2string(int n)
{
    string s;
    while(n>0)
    {
        char ch = '0'+n%10;
        s = ch+s;
        n /= 10;
    }
    return s;
}

bool prior(int a, int b)
{
    int ha=highest(a), hb=highest(b);
    if(ha!=hb) return ha < hb;
    string sa = num2string(a), sb = num2string(b);
    string ab = sa+sb, ba = sb+sa;
    return ab < ba;
}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return string();
        sort(numbers.begin(),numbers.end(),prior);
        string res;
        for(int n: numbers)
            res += num2string(n);
        return res;
    }
};