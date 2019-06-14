#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int OneRound(vector<int>& v, int MyPos, int subRest)
{
    vector<int> subV(v);
    queue<int> pos;
    pos.push(MyPos);
    bool success=true;
    while(!pos.empty())
    {
        if(subRest<=0){success=false;break;}
        int curPos = pos.front();
        pos.pop();
        subV[curPos]++;
        subRest--;
        if(curPos-1>=0)
        {
            if(subV[curPos-1]+1 < subV[curPos])
                pos.push(curPos-1);
        }
        if(curPos+1<v.size())
        {
            if(subV[curPos+1]+1 < subV[curPos])
                pos.push(curPos+1);
        }
    }
    if(success)
    {
        v = subV;
        return subRest;
    }
    return -1;
}

int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    if(K*M*N == 0 || K>N)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int> dollsCnt(N,0);
    dollsCnt[K-1] = 1;
    M -= 1;
    bool succ=true;
    while(M > 0)
    {
        M = OneRound(dollsCnt, K-1, M);
    }
    cout<<dollsCnt[K-1]<<endl;
    return 0;
}