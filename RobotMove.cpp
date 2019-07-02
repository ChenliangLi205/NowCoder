#include<stack>
#include<set>
class Solution {
public:
    int BitSum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows*cols==0) return 0;
        stack<pair<int,int>> s;
        pair<int,int> loc(0,0);
        set<pair<int,int>> visited;
        s.push(loc);
        while(!s.empty())
        {
            loc = s.top();
            s.pop();
            int bitSum = BitSum(loc.first)+BitSum(loc.second);
            if(bitSum <= threshold)
            {
                if(visited.find(loc)!=visited.end()) continue;
                visited.insert(loc);
                if(loc.first>0) s.push(make_pair(loc.first-1, loc.second));
                if(loc.first<rows-1) s.push(make_pair(loc.first+1, loc.second));
                if(loc.second>0) s.push(make_pair(loc.first, loc.second-1));
                if(loc.second<cols-1) s.push(make_pair(loc.first, loc.second+1));
            }
        }
        return visited.size();
    }
};