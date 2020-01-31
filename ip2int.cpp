#include <iostream>
using namespace std;

unsigned int ip2int(unsigned int* ip)
{
    unsigned long res = (ip[0] << 24) | (ip[1] << 16)
        | (ip[2] << 8) | ip[3];
    return res;
}

void int2ip(unsigned int n, unsigned int* ip)
{
    ip[0] = (n & 0xff000000) >> 24;
    ip[1] = (n & 0x00ff0000) >> 16;
    ip[2] = (n & 0x0000ff00) >> 8;
    ip[3] = n & 0x000000ff;
}

void getip(char* s, unsigned int* ip)
{
    unsigned int tmp = 0;
    int curIndex = 0;
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i] != '.')
        {
            tmp *= 10;
            tmp += (unsigned int)(s[i] - '0');
        }
        else
        {
            ip[curIndex++] = tmp;
            tmp = 0;
        }
    }
    ip[3] = tmp;
}

inline void showip(unsigned int* ip)
{
    cout << ip[0] << "." << ip[1]
        << "." << ip[2] << "." << ip[3]<< endl;
}

int main()
{
    char s[16];
    unsigned int n;
    while(cin >> s >> n)
    {
        unsigned int ip[4]={0,0,0,0};
        getip(s, ip);
        cout << ip2int(ip) << endl;
        int2ip(n, ip);
        showip(ip);
    }
    return 0;
}