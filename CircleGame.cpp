class Solution {
public:
    
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0) return -1;
        if(n == 1) return 1;
        vector<int> v;
        for(int i=0;i<=n-1;i++) v.push_back(i);
        int cnt=0;
        auto it = v.begin();
        while(v.size() > 1)
        {
            if(cnt == m-1)
            {
                v.erase(it);
                cnt = 0;
            }
            else
            {
                cnt++;
                ++it;
            }
            if(it==v.end()) it = v.begin();
        }
        return v.back();
    }
};