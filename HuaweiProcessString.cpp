#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const char decs[] = 
{'0','1','2','3','4','5','6','7','8','9',
 'a','b','c','d','e','f','A','B','C','D','E','F'};
const char reverse_decs[] =
{'0','8','4','C','2','A','6','E','1','9',
 '5','D','3','B','7','F','5','D','3','B','7','F'};

void ProcessString(char* s1, char* s2, char* output)
{
    char odds[100], evens[100];
    memset(odds, '\0', sizeof(odds));
    memset(evens, '\0', sizeof(evens));
    int cnt = 0, oddsCnt=0, evensCnt=0;
    for(int i=0;s1[i]!='\0';++i)
    {
        if(cnt % 2 != 0) odds[oddsCnt++] = s1[i];
        else evens[evensCnt++] = s1[i];
        ++cnt;
    }
    for(int i=0;s2[i]!='\0';++i)
    {
        if(cnt % 2 != 0) odds[oddsCnt++] = s2[i];
        else evens[evensCnt++] = s2[i];
        ++cnt;
    }
    sort(odds, odds+oddsCnt);
    sort(evens, evens+evensCnt);
    cnt = 0;
    oddsCnt = 0;
    evensCnt = 0;
    while(odds[oddsCnt]!='\0' || evens[evensCnt]!='\0')
    {
        if(cnt % 2 == 0)
            output[cnt++] = evens[evensCnt++];
        else
            output[cnt++] = odds[oddsCnt++];
    }
    for(cnt=0;output[cnt]!='\0';++cnt)
    {
        char c = output[cnt];
        if(c >= '0' && c <= '9')
            output[cnt] = reverse_decs[c-'0'];
        else if(c >= 'a' && c <= 'f')
            output[cnt] = reverse_decs[(char)10+c-'a'];
        else if(c >= 'A' && c <= 'F')
            output[cnt] = reverse_decs[(char)16+c-'A'];
    }
    return;
}

int main()
{
    char s1[201], s2[201], output[401];
    memset(output, '\0', sizeof(output));
    while(cin >> s1 >> s2)
    {
        ProcessString(s1, s2, output);
        for(int i=0;output[i]!='\0';++i)
            cout<<output[i];
        cout << endl;
        memset(output, '\0', sizeof(output));
    }
    return 0;
}