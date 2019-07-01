class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n==0) return 0;
        if(n<10) return 1;
        int sum = 0;
        int prev = 0;
        int cur = n;
        int bits = 1;
        while(cur > 0)
        {
            sum += bits * (cur/10);
            if(bits == 1)
            {
                if(cur%10 >= 1) sum+=1;
            }
            else
            {
                if(cur%10 == 1) sum += prev+1;
                if(cur%10 > 1) sum += bits;
            }
            
            bits *= 10;
            prev = n % bits;
            cur /= 10;
        }
        return sum;
    }
};