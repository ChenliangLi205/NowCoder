# include<iostream>
# include<vector>
using namespace std;
int main()
{
    vector<long> values = {1,5,10,50,100,500};
    vector<long> coins;
    for(int i=0;i<6;i++)
    {
        long c;
        cin>>c;
        coins.push_back(c);
    }
    long a;
    cin>>a;
    long total = 0;
    for(int i=0;i<6;i++)
        total += values[i] * coins[i];
    if(total < a)
    {
        cout<<"NOWAY"<<endl;
    }
    else
    {
        long left = a;
        int coin_idx = 5;
        long total_used = 0;
        while(left > 0 && coin_idx >= 0)
        {
            if(left >= values[coin_idx] && coins[coin_idx] > 0)
            {
                long coin_used = left / values[coin_idx];
                coin_used = coin_used <= coins[coin_idx] ? coin_used : coins[coin_idx];
                total_used += coin_used;
                left -= coin_used * values[coin_idx];
                coin_idx--;
            }
            else coin_idx--;
        }
        if(left == 0) cout<<total_used<<endl;
        else cout<<"NOWAY"<<endl;
    }
    return 0;
}