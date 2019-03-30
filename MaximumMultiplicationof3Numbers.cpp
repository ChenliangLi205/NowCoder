# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> A;
    long long tmp;
    while(cin>>tmp)
        A.push_back(tmp);
    if(A.size()==3)
        cout<<A[0]*A[1]*A[2]<<endl;
    else
    {
        vector<long long> max_pos;
        vector<long long> min_neg;
        long long max_neg = 0;
        bool have_zero = false;
        for(int i=0;i<n;i++)
        {
            if(A[i]==0)
            {
                have_zero=true;
            }
            if(A[i]>0)
            {
                if(max_pos.empty())
                    max_pos.push_back(A[i]);
                else
                {
                    bool added = false;
                    for(int j=0;j<max_pos.size();j++)
                    {
                        if(A[i] > max_pos[j])
                        {
                            max_pos.insert(max_pos.begin()+j, A[i]);
                            if(max_pos.size() > 3) max_pos.pop_back();
                            added = true;
                            break;
                        }
                    }
                    if(max_pos.size() < 3 && !added) max_pos.push_back(A[i]);
                }
            }
            if(A[i]<0)
            {
                if(max_neg == 0) max_neg = A[i];
                else max_neg = A[i] > max_neg ? A[i] : max_neg;
                if(min_neg.empty())
                    min_neg.push_back(A[i]);
                else
                {
                    bool added = false;
                    for(int j=0;j<min_neg.size();j++)
                    {
                        if(A[i] < min_neg[j])
                        {
                            min_neg.insert(min_neg.begin()+j, A[i]);
                            if(min_neg.size() > 2) min_neg.pop_back();
                            added = true;
                            break;
                        }
                    }
                    if(min_neg.size() < 2 && !added) min_neg.push_back(A[i]);
                }
            }
        }
        if(max_pos.size()+min_neg.size() < 3)
            cout<<0<<endl;
        else if(max_pos.size() == 1)
            cout<<max_pos[0]*min_neg[0]*min_neg[1]<<endl;
        else if(max_pos.size() == 2)
        {
            if(min_neg.size() < 2)
            {
                if(have_zero) cout<<0<<endl;
                else cout<<max_pos[0]*max_pos[1]*max_neg<<endl;
            }
            else
            {
                cout<<min_neg[0] * min_neg[1] * max_pos[0];
            }
        }
        else if(max_pos.size() == 0)
        {
            if(have_zero) cout<<0<<endl;
            else cout<<min_neg[0]*min_neg[1]*max_neg<<endl;
        }
        else if(max_pos.size() == 3)
        {
            if(min_neg.size() < 2)
                cout<<max_pos[0]*max_pos[1]*max_pos[2]<<endl;
            else
            {
                long long posMult = max_pos[0] * max_pos[1] * max_pos[2];
                long long negMult = min_neg[0] * min_neg[1] * max_pos[0];
                if(posMult > negMult) cout<<posMult<<endl;
                else cout<<negMult<<endl;
            }
        }
    }
    return 0;
}