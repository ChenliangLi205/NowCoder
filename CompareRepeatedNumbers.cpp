# include<iostream>
# include<string>
using namespace std;

void Compare(string s1, string s2){
    if(s1.size() > s2.size()){
        cout<<"Greater"<<endl;
        return;
    }
    if(s1.size() < s2.size()){
        cout<<"Less"<<endl;
        return;
    }
    for(decltype(s1.size()) i=0;i<s1.size();i++)
    {
        if(s1[i] > s2[i]){
            cout<<"Greater"<<endl;
            return;
        }
        if(s1[i] < s2[i]){
            cout<<"Less"<<endl;
            return;
        }
    }
    cout<<"Equal"<<endl;
    return;
}

int main()
{
    string n1,n2;
    int r1,r2;
    cin>>n1>>r1>>n2>>r2;
    string s1 = n1;
    string s2 = n2;
    for(int i=1;i<r1;i++) s1 += n1;
    for(int i=1;i<r2;i++) s2 += n2;
    Compare(s1, s2);
    return 0;
}