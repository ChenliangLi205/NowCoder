class Solution {
public:
    int cutRope(int number) {
        
        if(number <= 2) return 1;
        
        int dp[61];
        int maxLen=number;
        dp[0] = 0;
        dp[1] = 1;
        
        int max = 0;
        for(int i=2;i<number;++i)
        {
            dp[i] = i;
            for(int j=1;j<i;++j)
            {
                if(dp[j]*(i-j) > i)
                    dp[i] = dp[j]*(i-j);
            }
            if(dp[i] * (number-i) > max)
                max = dp[i] * (number-i);
        }
        return max;
    }
};