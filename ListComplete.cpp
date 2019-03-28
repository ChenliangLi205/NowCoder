# include<iostream>
# include<vector>
using namespace std;
int main()
{
    int offset, display, l1, l2;
    vector<int> s1;
    vector<int> e1;
    vector<int> s2;
    vector<int> e2;
    while(cin>>offset>>display>>l1>>l2)
    {
        int start1, end1, start2, end2;
        if(offset < l1)
        {
            start1 = offset;
            int left1 = l1 - offset;
            if(display<=left1)
            {
                end1 = start1+display;
                start2 = 0;
                end2 = 0;
            }
            else
            {
                end1 = l1;
                start2 = 0;
                int chosen2 = display - left1;
                if(chosen2 > l2) end2=l2;
                else end2 = chosen2;
            }
        }
        else
        {
            start1 = l1;
            end1 = l1;
            start2 = offset-l1;
            int left2 = l2 - (offset-l1);
            if(left2<=0) {start2=l2;end2=l2;}
            else if(left2 < display) end2=l2;
            else end2 = start2 + display;
        }
        s1.push_back(start1);
        e1.push_back(end1);
        s2.push_back(start2);
        e2.push_back(end2);
    }
    for(int i=0;i<s1.size();i++)
        cout<<s1[i]<<" "<<e1[i]<<" "<<s2[i]<<" "<<e2[i]<<endl;
    return 0;
}