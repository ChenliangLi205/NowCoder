class Solution {
public:
    int min(int a, int b, int c)
    {
        int mid = a < b ? a : b;
        return mid < c ? mid : c;
    }
    
    int GetUglyNumber_Solution(int index) {
        int dp[index+1];
        if(index==1) return 1;
        dp[0] = 0;
        dp[1] = 1;
        int idx2=1, idx3=1, idx5=1;
        int idx = 2;
        int next2 = dp[idx2]*2;
        int next3 = dp[idx3]*3;
        int next5 = dp[idx5]*5;
        while(idx <= index)
        {
            int m = min(next2,next3,next5);
            dp[idx++] = m;
            if(m==next2)
            {
                idx2++;
                if(idx2 > index) next2=0x7fffffff;
                else next2 = dp[idx2]*2;
            }
            if(m==next3)
            {
                idx3++;
                if(idx3 > index) next3=0x7fffffff;
                else next3 = dp[idx3]*3;
            }
            if(m==next5)
            {
                idx5++;
                if(idx5 > index) next5=0x7fffffff;
                else next5 = dp[idx5]*5;
            }
        }
        return dp[index];
    }
};