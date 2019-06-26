#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int Rcnt = 0;
    int Gcnt = 0;
    for(char c : s)
    {
        if(c=='R') Rcnt++;
        else Gcnt++;
    }
    int MinPaint = Rcnt < Gcnt ? Rcnt : Gcnt;
    int leftR=0,leftG=0;
    int rightR=Rcnt, rightG=Gcnt;
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1] == 'R') {leftR++;rightR--;}
        else {leftG++;rightG--;}
        int paint = leftG+rightR;
        MinPaint = MinPaint < paint ? MinPaint : paint;
    }
    cout << MinPaint << endl;
    return 0;
}
