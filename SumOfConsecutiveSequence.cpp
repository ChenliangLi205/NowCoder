class Solution {
public:

vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int phigh = 2,plow = 1;
        int curSum = 3;
        while(phigh > plow && plow < sum && phigh < sum){
            
            if( curSum < sum)
            {
                phigh++;
                curSum+=phigh;
            }
             
            else if( curSum == sum)
            {
                vector<int> res;
                for(int i = plow; i<=phigh; i++)
                    res.push_back(i);
                allRes.push_back(res);
                curSum -= plow;
                plow++;
            }
             
            else
            {
                curSum-=plow;
                plow++;
            }
        }
        return allRes;
    }
};