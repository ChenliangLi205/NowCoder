#include<algorithm>
#include<set>
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int firstNonZeroIdx = 0;
        while(numbers[firstNonZeroIdx]==0 &&
              firstNonZeroIdx < numbers.size()) firstNonZeroIdx++;
        int duplicateIdx = firstNonZeroIdx;
        set<int> visited;
        while(duplicateIdx < numbers.size())
        {
            if(visited.find(numbers[duplicateIdx])!=visited.end())
                return false;
            visited.insert(numbers[duplicateIdx++]);
        }
        if(numbers.back()-numbers[firstNonZeroIdx]<=numbers.size()-1)
            return true;
        else return false;
    }
};