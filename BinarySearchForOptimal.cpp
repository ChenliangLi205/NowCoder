#include<bits/stdc++.h>
using namespace std;

int HoursToEat(int speed, const vector<int>& v)
{
    int hours = 0;
    for(int i:v)
    {
        hours += i/speed;
        if(i%speed != 0) ++hours;
    }
    return hours;
}

int main()
{
    int MinPile=1, MaxPile=-1, MidPile, hours;
    vector<int> piles;
    int pile, MaxHours;
    while(cin>>pile)
    {
        piles.push_back(pile);
        if(MaxPile < pile) MaxPile = pile;
    }
    MaxHours = piles.back();
    piles.pop_back();
    MidPile = (MinPile + MaxPile) / 2;
    while(MinPile < MaxPile)
    {
        hours = HoursToEat(MidPile, piles);
        if(hours <= MaxHours)
        {
            if(MaxPile == MidPile) break;
            MaxPile = MidPile;
        }
        else
        {
            MinPile = MidPile+1;
        }
        MidPile = (MinPile + MaxPile) / 2;
    }
    cout << MidPile << endl;
    return 0;
}