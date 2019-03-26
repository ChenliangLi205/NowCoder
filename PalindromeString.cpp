# include<iostream>
# include<string>
# include<algorithm>
using namespace std;

bool isPalin(string s){
    string::size_type left=0, right=s.size()-1;
    while(left<right) if(s[left++]!=s[right--]) return false;
    return true;
}

int main(){
    string s;
    cin>>s;
    if(isPalin(s)) cout<<s.size()<<endl;
    else
    {
        int len=1;
        string new_s = s;
        while(len<=s.size()){
            string toAdd = s.substr(0,len);
            reverse(toAdd.begin(), toAdd.end());
            new_s += toAdd;
            if(isPalin(new_s)) break;
            len++;
            new_s = s;
        }
        cout<<new_s.size()<<endl;
    }
    return 0;
}
