# include<iostream>
using namespace std;

int helper(int target, int start, int end){
    if(target == 0) return 1;
    if(start>target || start>end) return 0;
    int ans = 0;
    for(int i=start;i<=end;i++){
        ans += helper(target-i,i+1,end);
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans += helper(m-i,i+1,n);
    cout<<ans<<endl;
    return 0;
}
