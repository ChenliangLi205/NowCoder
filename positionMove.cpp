#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int toNumber(const string& num)
{
    int res = 0;
    for(char c : num)
    {
        res *= 10;
        if(c < '0' || c > '9') return 0;
        res += (int)(c-'0');
    }
    return res;
}

void moveLeft(const string& num, int& x, int& y)
{
    x -= toNumber(num);
    return;
}

void moveRight(const string& num, int& x, int& y)
{
    x += toNumber(num);
    return ;
}

void moveUp(const string& num, int& x, int& y)
{
    y += toNumber(num);
    return ;
}

void moveDown(const string& num, int& x, int& y)
{
    y -= toNumber(num);
    return ;
}

void move(const string& order, int& x, int& y)
{
    if(order.size() < 2 || order.size() > 3)
        return ;
    switch(order[0])
    {
        case 'A':
            moveLeft(string(order.begin()+1, order.end()), x, y);
            break;
        case 'W':
            moveUp(string(order.begin()+1, order.end()), x, y);
            break;
        case 'D':
            moveRight(string(order.begin()+1, order.end()), x, y);
            break;
        case 'S':
            moveDown(string(order.begin()+1, order.end()), x, y);
            break;
        default:
            break;
    }
    return ;
}
int main()
{
    string raw_input;
    while(cin >> raw_input)
    {
        vector<string> orders;
        string order;
        istringstream iss(raw_input);
        while(getline(iss, order, ';'))
            orders.push_back(order);
        int x=0,y=0;
        for(string o : orders)
        {
            move(o, x, y);
        }
        cout << x << "," << y<< endl;
    }
    return 0;
}