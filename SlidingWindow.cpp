class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.size() < size || size <= 0) return res;
        if(num.size() == size)
        {
            int m = num[0];
            for(int n:num)
            {
                if(n > m) m = n;
            }
            res.push_back(m);
        }
        else
        {
            int loc=0;
            for(int i=1;i<size;i++)
            {
                if(num[i]>num[loc]) loc = i;
            }
            res.push_back(num[loc]);
            int last=size;
            int start=1;
            while(last<num.size())
            {
                loc--;
                if(loc<0)
                {
                    loc = 0;
                    for(int i=1;i<size;i++)
                    {
                        if(num[loc+start] < num[i+start])
                            loc = i;
                    }
                }
                if(num[last] >= num[loc+start])
                    loc = size-1;
                res.push_back(num[loc+start]);
                last++;
                start++;
            }
        }
        return res;
    }
};