# include<iostream>
# include<set>
using namespace std;
int main()
{
    int L,R,W;
    cin>>L>>R>>W;
    set<int> lefts;
    lefts.insert(L);
    int leftSpace = L - L%W;
    bool read=true;
    while(true)
    {
        if(leftSpace < W && L-leftSpace < R) 
        {
            cout<<"DEADLOCK"<<endl;
            break;
        }
        if(lefts.find(leftSpace)!=lefts.end())
        {
            cout<<"OK"<<endl;
            break;
        }
        lefts.insert(leftSpace);
        if(L-leftSpace >= R) {leftSpace = L-(L-leftSpace)%R;continue;}
        if(leftSpace >= W) {leftSpace = leftSpace%W;continue;}
    }
    return 0;
}