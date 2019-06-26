#include<numeric>
#include<vector>
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0) return 0;
        if(number <= 2) return number;
        std::vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);
        for(int i=3;i<=number;i++)
        {
            int sum = accumulate(dp.begin(), dp.end(), 1);
            dp.push_back(sum);
        }
        return dp.back();
    }
};