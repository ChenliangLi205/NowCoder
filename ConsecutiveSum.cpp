class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        if(array.size() == 1) return array[0];
        int curSum=array[0];
        int max=curSum;
        for(int i : vector<int>(array.begin()+1, array.end()))
        {
            if(i>=0)
            {
                if(curSum > 0) curSum += i;
                else curSum = i;
            }
            else
            {
                if(curSum+i < 0) curSum = i;
                else curSum += i;
            }
            max = max > curSum ? max : curSum;
        }
        return max;
    }
};