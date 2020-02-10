#include <iostream>

using namespace std;

int count(int apples, int plates, int maxAppleOnePlate)
{
    if(apples == 0) return 1;
    if(maxAppleOnePlate * plates < apples) return 0;
    if(plates == 1)
    {
        return 1;
    }
    int thisPlate=1,left=apples-1,res=0;
    for(; thisPlate<=maxAppleOnePlate && thisPlate<=apples ;
        ++thisPlate, --left)
        res += count(left, plates-1, thisPlate);
    return res;
}

int main()
{
    int m,n;
    while(cin >> m >> n)
    {
        cout << count(m,n,m) << endl;
    }
    return 0;
}